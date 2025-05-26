#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>
#include <QMainWindow>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>

#include "dockwidget.h"

namespace Ui { class DockWidget; }

class DockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockWidget(QWidget *parent = nullptr);
    ~DockWidget();

private:
    Ui::DockWidget *ui;

    DockWidget *dockWidget;             // 도크 매니저 위젯
    QDockWidget *dwLB;                  // 왼쪽 하단 도크 위젯
    QDockWidget *dockManager;           // 왼쪽 상단 도크 위젯
    QMainWindow *internalMainWindow;    // DockWidget 내부의 QMainWindow

    QTextEdit *dwCT;                  // 중앙 상단 텍스트 에디터
    QTextEdit *dwCB;                  // 중앙 하단 텍스트 에디터
    QSplitter *splitter;             // 중앙 분할기
};

#endif // DOCKWIDGET_H
