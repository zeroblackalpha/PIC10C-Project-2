#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grader.h"
#include "qstring.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Grader *grade = new Grader();

    // Connect all signals and slots
    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), grade, SLOT(updateTab(int)));
    QObject::connect(ui->SchemaA, SIGNAL(toggled(bool)), grade, SLOT(updateSchema(bool)));
    QObject::connect(ui->SchemaB, SIGNAL(toggled(bool)), grade, SLOT(updateSchema(bool)));
    QObject::connect(ui->PIC10BHW1, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW1(double)));
    QObject::connect(ui->PIC10BHW2, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW2(double)));
    QObject::connect(ui->PIC10BHW3, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW3(double)));
    QObject::connect(ui->PIC10BHW4, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW4(double)));
    QObject::connect(ui->PIC10BHW5, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW5(double)));
    QObject::connect(ui->PIC10BHW6, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW6(double)));
    QObject::connect(ui->PIC10BHW7, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BHW7(double)));
    QObject::connect(ui->PIC10BMT1, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BMT1(double)));
    QObject::connect(ui->PIC10BMT2, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BMT2(double)));
    QObject::connect(ui->PIC10BFE, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10BFE(double)));
    QObject::connect(ui->PIC10CHW1, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10CHW1(double)));
    QObject::connect(ui->PIC10CHW2, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10CHW2(double)));
    QObject::connect(ui->PIC10CHW3, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10CHW3(double)));
    QObject::connect(ui->PIC10CMT, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10CMT(double)));
    QObject::connect(ui->PIC10CFP, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10CFP(double)));
    QObject::connect(ui->PIC10CFE, SIGNAL(valueChanged(double)), grade, SLOT(updatePIC10CFE(double)));
    QObject::connect(grade, SIGNAL(valueChanged(QString)), ui->FinalGrade, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
