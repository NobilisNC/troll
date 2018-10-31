#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QScreen>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_b_go_clicked()
{
  QScreen *screen = QGuiApplication::primaryScreen();

   if (!screen)
       return;

   this->hide();

   QTimer::singleShot(500, [=]{
        screenshot_ = screen->grabWindow(0);
        displayScreenshot();
   });


}

void MainWindow::displayScreenshot()
{
  QLabel* label = new QLabel();
  label->setPixmap(screenshot_);

  label->showFullScreen();
}
