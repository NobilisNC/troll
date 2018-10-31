#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void on_b_go_clicked();
    void displayScreenshot();

  private:
    Ui::MainWindow *ui;
    QPixmap screenshot_;
};

#endif // MAINWINDOW_H
