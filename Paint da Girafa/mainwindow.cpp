#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "draft.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filhin = new draft();

    connect(ui->color_lineEdit, SIGNAL(textChanged(QString)), ui->widget, SLOT(setColorPen(QString)));
    connect(ui->Squarebutton, SIGNAL(clicked()), ui->widget, SLOT(setvariavelsquare()));
    connect(ui->Circlebutton, SIGNAL(clicked()), ui->widget, SLOT(setvariavelcircle()));
    connect(ui->Fashiosquarebutton, SIGNAL(clicked()), ui->widget, SLOT(setvariavelfashionsquare()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
