#include "dockwidget.h"
#include "ui_dockwidget.h"

DockWidget::DockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DockWidget)
{
    ui->setupUi(this);                                              // 필요 시 Qt Designer에서 .ui 파일 사용 가능
    setObjectName("DockWidget");
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    internalMainWindow = new QMainWindow(this);

    dockManager = new QDockWidget("Left Top", internalMainWindow);  // 왼쪽 상단 도크
    dockManager->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockManager->setWidget(new QTextEdit("Left Top"));

    internalMainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockManager);

    dwLB = new QDockWidget("Left Bottom", internalMainWindow);      // 왼쪽 하단 도크
    dwLB->setAllowedAreas(Qt::LeftDockWidgetArea);
    dwLB->setWidget(new QTextEdit("Left Bottom"));

    internalMainWindow->addDockWidget(Qt::LeftDockWidgetArea, dwLB);
    internalMainWindow->splitDockWidget(dockManager, dwLB, Qt::Vertical);

    dwCT = new QTextEdit("Center Top");                             // 중앙 분할기
    dwCB = new QTextEdit("Center Bottom");

    splitter = new QSplitter(Qt::Vertical, internalMainWindow);
    splitter->addWidget(dwCT);
    splitter->addWidget(dwCB);

    internalMainWindow->setCentralWidget(splitter);

    this->setWidget(internalMainWindow);                            // 최종적으로 내부 QMainWindow를 DockWidget에 설정
}

DockWidget::~DockWidget()
{
    delete ui;
}
