#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mdiArea(new QMdiArea(this))
    , addButton(new QPushButton("＋", this))
    , toolBar(new QToolBar("Manager", this))
    , dockWidget(nullptr)
    , contentWidget(nullptr)
    , container(nullptr)
    , layout(nullptr)
    , subWindow(nullptr)
{
    ui->setupUi(this);
    setCentralWidget(mdiArea);

    // 툴바 설정
    toolBar->setContextMenuPolicy(Qt::PreventContextMenu);
    toolBar->setMovable(false);

    QWidget *spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacer);
    toolBar->addWidget(addButton);

    addToolBar(toolBar);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddWidgetClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddWidgetClicked()
{
    dockWidget = new DockWidget;
    contentWidget = dockWidget->widget();

    container = new QWidget;
    layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(contentWidget);

    subWindow = new QMdiSubWindow;
    subWindow->setWidget(container);
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    mdiArea->addSubWindow(subWindow);
    subWindow->resize(600, 400);
    subWindow->show();

    arrangeSubWindows();
}

void MainWindow::arrangeSubWindows()
{
    QList<QMdiSubWindow*> windows = mdiArea->subWindowList();
    int count = windows.count();
    if (count == 0) return;

    int columns = static_cast<int>(std::ceil(std::sqrt(count)));

    int winWidth = 300;
    int winHeight = 200;
    int margin = 0;

    for (int i = 0; i < count; ++i)
    {
        int row = i / columns;
        int col = i % columns;

        int x = col * (winWidth + margin);
        int y = row * (winHeight + margin);

        windows[i]->move(x, y);
        windows[i]->resize(winWidth, winHeight);
    }
}
