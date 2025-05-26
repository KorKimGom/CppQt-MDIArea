#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMdiSubWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QWidget>

#include <cmath>

#include "dockwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddWidgetClicked();
    void arrangeSubWindows();

private:
    Ui::MainWindow *ui;

    QMdiArea *mdiArea;
    QPushButton *addButton;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *fileMenu;

    DockWidget *dockWidget;
    QWidget *contentWidget;
    QWidget *container;
    QVBoxLayout *layout;
    QMdiSubWindow *subWindow;
};

#endif // MAINWINDOW_H
