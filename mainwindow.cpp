#define INF 9999

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Algorithms.h"

using namespace std;

void MainWindow::dijcstraButton(){
    /*  Создание массива весов  */
    double v [10][10] =
        {0, 3.1943, 10.433, 2.3425, INF, INF, INF, INF, INF, INF,
         3.1943, 0, INF, 4.376, 6.549, INF, INF, INF, INF, INF,
         10.433, INF, 0, INF, INF, 7.341, INF, INF, INF, INF,
         2.3425, 4.376, INF, 0, 5.982, 7.547, 5.2475, INF, INF, INF,
         INF, 6.549, INF, 5.982, 0, INF, 6.4318, 5.4566, INF, INF,
         6.455, INF, 7.341, 7.547, INF, 0, 6.7876, INF, 8.3428, INF,
         INF, INF, INF, 5.2475, 6.4318, 6.7876, 0, 4.87, 5.1207, INF,
         INF, INF, INF, INF, 5.4566, INF, 4.87, 0, 2.1452, 6.8721,
         INF, INF, INF, INF, INF, 8.3428, 5.1207, 2.1452, 0, 7.4321,
         INF, INF, INF, INF, INF, INF, INF, 6.8721, 7.4321, 0};

    /*  Заполнение таблицы  */
    vector<ver> paths(10);
    int a = ui->spinBox->value();
    paths = Dijcstra(a, v);
    for(int i = 0; i < 10; i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromStdString(paths[i].path));
        ui->tableWidget->setItem(i - 1, 3, item);
        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(paths[i].minval));
        ui->tableWidget->setItem(i - 1, 2, item2);
    }
}

void MainWindow::lr1Button(){
    ui->pushButton->setVisible(true);
    ui->spinBox->setVisible(true);
    ui->label->setVisible(true);
    ui->tableWidget->setVisible(true);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QLabel *label1_1 = new QLabel(this);
    label1_1->setFixedSize(16, 16);
    label1_1->setText("1");
    label1_1->setGeometry(200 + 8, 100 + 4, 200 + 24, 100 + 20);
    label1_1->show();

    QLabel *label2_1 = new QLabel(this);
    label2_1->setFixedSize(16, 16);
    label2_1->setText("2");
    label2_1->setGeometry(100 + 8, 150 + 4, 100 + 24, 150 + 20);
    label2_1->show();

    QLabel *label3_1 = new QLabel(this);
    label3_1->setFixedSize(16, 16);
    label3_1->setText("3");
    label3_1->setGeometry(300 + 8, 150 + 4, 300 + 24, 150 + 20);
    label3_1->show();

    QLabel *label4_1 = new QLabel(this);
    label4_1->setFixedSize(16, 16);
    label4_1->setText("4");
    label4_1->setGeometry(200 + 8, 200 + 4, 200 + 24, 200 + 20);
    label4_1->show();

    QLabel *label5_1 = new QLabel(this);
    label5_1->setFixedSize(16, 16);
    label5_1->setText("5");
    label5_1->setGeometry(100 + 8, 250 + 4, 100 + 24, 250 + 20);
    label5_1->show();

    QLabel *label6_1 = new QLabel(this);
    label6_1->setFixedSize(16, 16);
    label6_1->setText("6");
    label6_1->setGeometry(300 + 8, 250 + 4, 300 + 24, 250 + 20);
    label6_1->show();

    QLabel *label7_1 = new QLabel(this);
    label7_1->setFixedSize(16, 16);
    label7_1->setText("7");
    label7_1->setGeometry(200 + 8, 300 + 4, 200 + 24, 300 + 20);
    label7_1->show();

    QLabel *label8_1 = new QLabel(this);
    label8_1->setFixedSize(16, 16);
    label8_1->setText("8");
    label8_1->setGeometry(100 + 8, 350 + 4, 100 + 24, 350 + 20);
    label8_1->show();

    QLabel *label9_1 = new QLabel(this);
    label9_1->setFixedSize(16, 16);
    label9_1->setText("9");
    label9_1->setGeometry(300 + 8, 350 + 4, 300 + 24, 350 + 20);
    label9_1->show();

    QLabel *label10_1 = new QLabel(this);
    label10_1->setFixedSize(16, 16);
    label10_1->setText("10");
    label10_1->setGeometry(200 + 4, 400 + 4, 200 + 24, 400 + 24);
    label10_1->show();

    //1  1-4
        QLabel *label1_2 = new QLabel(this);
        label1_2->setFixedSize(16, 16);
        label1_2->setText("1");
        label1_2->setGeometry(195 + 8, 125 + 4, 195 + 24, 125 + 20);
        label1_2->setStyleSheet("QLabel {font-size : 18px}");
        label1_2->show();
        QLabel *label1_3 = new QLabel(this);
        label1_3->setFixedSize(38, 16);
        label1_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label1_3->setText("2.3425");
        label1_3->setGeometry(185 + 8, 145 + 4, 185 + 24, 145 + 20);
        label1_3->show();

    //2  1-2
        QLabel *label2_2 = new QLabel(this);
        label2_2->setFixedSize(16, 16);
        label2_2->setText("2");
        label2_2->setGeometry(144 + 8, 110 + 4, 144 + 24, 110 + 20);
        label2_2->setStyleSheet("QLabel {font-size : 18px}");
        label2_2->show();
        QLabel *label2_3 = new QLabel(this);
        label2_3->setFixedSize(38, 16);
        label2_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label2_3->setText("3.1943");
        label2_3->setGeometry(140 + 8, 130 + 4, 140 + 24, 130 + 20);
        label2_3->show();

    //3  1-3
        QLabel *label3_2 = new QLabel(this);
        label3_2->setFixedSize(16, 16);
        label3_2->setText("3");
        label3_2->setGeometry(240 + 8, 107 + 4, 240 + 24, 107 + 20);
        label3_2->setStyleSheet("QLabel {font-size : 18px}");
        label3_2->show();
        QLabel *label3_3 = new QLabel(this);
        label3_3->setFixedSize(38, 16);
        label3_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label3_3->setText("10.433");
        label3_3->setGeometry(240 + 8, 125 + 4, 240 + 24, 125 + 20);
        label3_3->show();

    //4  2-5
        QLabel *label4_2 = new QLabel(this);
        label4_2->setFixedSize(16, 16);
        label4_2->setText("4");
        label4_2->setGeometry(90 + 8, 180 + 4, 90 + 24, 180 + 20);
        label4_2->setStyleSheet("QLabel {font-size : 18px}");
        label4_2->show();
        QLabel *label4_3 = new QLabel(this);
        label4_3->setFixedSize(38, 16);
        label4_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label4_3->setText("6.549");
        label4_3->setGeometry(90 + 8, 200 + 4, 90 + 24, 200 + 20);
        label4_3->show();

    //5  2-4
        QLabel *label5_2 = new QLabel(this);
        label5_2->setFixedSize(16, 16);
        label5_2->setText("5");
        label5_2->setGeometry(140 + 8, 157 + 4, 140 + 24, 157 + 20);
        label5_2->setStyleSheet("QLabel {font-size : 18px}");
        label5_2->show();
        QLabel *label5_3 = new QLabel(this);
        label5_3->setFixedSize(38, 16);
        label5_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label5_3->setText("4.376");
        label5_3->setGeometry(135 + 8, 175 + 4, 135 + 24, 175 + 20);
        label5_3->show();

    //6  4-5
        QLabel *label6_2 = new QLabel(this);
        label6_2->setFixedSize(16, 16);
        label6_2->setText("6");
        label6_2->setGeometry(140 + 8, 213 + 4, 140 + 24, 213 + 20);
        label6_2->setStyleSheet("QLabel {font-size : 18px}");
        label6_2->show();
        QLabel *label6_3 = new QLabel(this);
        label6_3->setFixedSize(38, 16);
        label6_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label6_3->setText("5.982");
        label6_3->setGeometry(135 + 8, 232 + 4, 135 + 24, 232 + 20);
        label6_3->show();

    //7  3-6
        QLabel *label7_2 = new QLabel(this);
        label7_2->setFixedSize(16, 16);
        label7_2->setText("7");
        label7_2->setGeometry(305 + 8, 180 + 4, 305 + 24, 180 + 20);
        label7_2->setStyleSheet("QLabel {font-size : 18px}");
        label7_2->show();
        QLabel *label7_3 = new QLabel(this);
        label7_3->setFixedSize(38, 16);
        label7_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label7_3->setText("7.341");
        label7_3->setGeometry(290 + 8, 200 + 4, 290 + 24, 200 + 20);
        label7_3->show();

    //8  1-6
        QLabel *label8_2 = new QLabel(this);
        label8_2->setFixedSize(16, 16);
        label8_2->setText("8");
        label8_2->setGeometry(252 + 8, 160 + 4, 252 + 24, 160 + 20);
        label8_2->setStyleSheet("QLabel {font-size : 18px}");
        label8_2->show();
        QLabel *label8_3 = new QLabel(this);
        label8_3->setFixedSize(38, 16);
        label8_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label8_3->setText("6.455");
        label8_3->setGeometry(242 + 8, 180 + 4, 242 + 24, 180 + 20);
        label8_3->show();

    //9  4-6
        QLabel *label9_2 = new QLabel(this);
        label9_2->setFixedSize(16, 16);
        label9_2->setText("9");
        label9_2->setGeometry(252 + 8, 210 + 4, 252 + 24, 210 + 20);
        label9_2->setStyleSheet("QLabel {font-size : 18px}");
        label9_2->show();
        QLabel *label9_3 = new QLabel(this);
        label9_3->setFixedSize(38, 16);
        label9_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label9_3->setText("7.547");
        label9_3->setGeometry(242 + 8, 230 + 4, 242 + 24, 230 + 20);
        label9_3->show();

    //10 4-7
        QLabel *label10_2 = new QLabel(this);
        label10_2->setFixedSize(20, 16);
        label10_2->setText("10");
        label10_2->setGeometry(205 + 8, 240 + 4, 205 + 24, 240 + 20);
        label10_2->setStyleSheet("QLabel {font-size : 18px}");
        label10_2->show();
        QLabel *label10_3 = new QLabel(this);
        label10_3->setFixedSize(38, 16);
        label10_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label10_3->setText("5.2475");
        label10_3->setGeometry(190 + 8, 260 + 4, 190 + 24, 260 + 20);
        label10_3->show();

    //11 5-7
        QLabel *label11_2 = new QLabel(this);
        label11_2->setFixedSize(20, 16);
        label11_2->setText("11");
        label11_2->setGeometry(150 + 8, 260 + 4, 150 + 24, 260 + 20);
        label11_2->setStyleSheet("QLabel {font-size : 18px}");
        label11_2->show();
        QLabel *label11_3 = new QLabel(this);
        label11_3->setFixedSize(38, 16);
        label11_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label11_3->setText("6.4318");
        label11_3->setGeometry(140 + 8, 280 + 4, 140 + 24, 280 + 20);
        label11_3->show();

    //12 6-7
        QLabel *label12_2 = new QLabel(this);
        label12_2->setFixedSize(20, 16);
        label12_2->setText("12");
        label12_2->setGeometry(235 + 8, 260 + 4, 235 + 24, 260 + 20);
        label12_2->setStyleSheet("QLabel {font-size : 18px}");
        label12_2->show();
        QLabel *label12_3 = new QLabel(this);
        label12_3->setFixedSize(38, 16);
        label12_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label12_3->setText("6.7876");
        label12_3->setGeometry(225 + 8, 280 + 4, 225 + 24, 280 + 20);
        label12_3->show();

    //13 5-8
        QLabel *label13_2 = new QLabel(this);
        label13_2->setFixedSize(20, 16);
        label13_2->setText("13");
        label13_2->setGeometry(82 + 8, 280 + 4, 82 + 24, 280 + 20);
        label13_2->setStyleSheet("QLabel {font-size : 18px}");
        label13_2->show();
        QLabel *label13_3 = new QLabel(this);
        label13_3->setFixedSize(38, 16);
        label13_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label13_3->setText("5.4566");
        label13_3->setGeometry(88 + 8, 300 + 4, 88 + 24, 300 + 20);
        label13_3->show();

    //14 7-8
        QLabel *label14_2 = new QLabel(this);
        label14_2->setFixedSize(20, 16);
        label14_2->setText("14");
        label14_2->setGeometry(140 + 8, 305 + 4, 140 + 24, 305 + 20);
        label14_2->setStyleSheet("QLabel {font-size : 18px}");
        label14_2->show();
        QLabel *label14_3 = new QLabel(this);
        label14_3->setFixedSize(24, 16);
        label14_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label14_3->setText("4.87");
        label14_3->setGeometry(135 + 8, 325 + 4, 135 + 24, 325 + 20);
        label14_3->show();

    //15 8-10
        QLabel *label15_2 = new QLabel(this);
        label15_2->setFixedSize(20, 16);
        label15_2->setText("15");
        label15_2->setGeometry(140 + 8, 395 + 4, 140 + 24, 395 + 20);
        label15_2->setStyleSheet("QLabel {font-size : 18px}");
        label15_2->show();
        QLabel *label15_3 = new QLabel(this);
        label15_3->setFixedSize(38, 16);
        label15_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label15_3->setText("6.8721");
        label15_3->setGeometry(135 + 8, 375 + 4, 135 + 24, 375 + 20);
        label15_3->show();

    //16 6-9
        QLabel *label16_2 = new QLabel(this);
        label16_2->setFixedSize(22, 16);
        label16_2->setText("16");
        label16_2->setGeometry(305 + 8, 290 + 4, 305 + 24, 290 + 20);
        label16_2->setStyleSheet("QLabel {font-size : 18px}");
        label16_2->show();
        QLabel *label16_3 = new QLabel(this);
        label16_3->setFixedSize(38, 16);
        label16_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label16_3->setText("8.3428");
        label16_3->setGeometry(290 + 8, 310 + 4, 290 + 24, 310 + 20);
        label16_3->show();

    //17 7-9
        QLabel *label17_2 = new QLabel(this);
        label17_2->setFixedSize(22, 16);
        label17_2->setText("17");
        label17_2->setGeometry(245 + 8, 310 + 4, 245 + 24, 310 + 20);
        label17_2->setStyleSheet("QLabel {font-size : 18px}");
        label17_2->show();
        QLabel *label17_3 = new QLabel(this);
        label17_3->setFixedSize(38, 16);
        label17_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label17_3->setText("5.1207");
        label17_3->setGeometry(245 + 8, 330 + 4, 245 + 24, 330 + 20);
        label17_3->show();

    //18 8-9
        QLabel *label18_2 = new QLabel(this);
        label18_2->setFixedSize(20, 16);
        label18_2->setText("18");
        label18_2->setGeometry(195 + 8, 330 + 4, 195 + 24, 330 + 20);
        label18_2->setStyleSheet("QLabel {font-size : 18px}");
        label18_2->show();
        QLabel *label18_3 = new QLabel(this);
        label18_3->setFixedSize(38, 16);
        label18_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label18_3->setText("2.1452");
        label18_3->setGeometry(190 + 8, 350 + 4, 190 + 24, 350 + 20);
        label18_3->show();

    //19 9-10
        QLabel *label19_2 = new QLabel(this);
        label19_2->setFixedSize(20, 16);
        label19_2->setText("19");
        label19_2->setGeometry(235 + 8, 395 + 4, 235 + 24, 395 + 20);
        label19_2->setStyleSheet("QLabel {font-size : 18px}");
        label19_2->show();
        QLabel *label19_3 = new QLabel(this);
        label19_3->setFixedSize(38, 16);
        label19_3->setStyleSheet("QLabel {color : green; background-color : white;}");
        label19_3->setText("7.4321");
        label19_3->setGeometry(230 + 8, 375 + 4, 230 + 24, 375 + 20);
        label19_3->show();

    /*  Заполнение таблицы  */
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(10);
    QStringList hLabels;
    hLabels<<"Расстояние"<<"Путь";
    ui->tableWidget->setHorizontalHeaderLabels(hLabels);
    dijcstraButton();
    connect(ui->pushButton, SIGNAL (released()), this, SLOT (dijcstraButton()));
    connect(ui->pushButton_2, SIGNAL (released()), this, SLOT (lr1Button()));
    ui->pushButton->setVisible(false);
    ui->spinBox->setVisible(false);
    ui->label->setVisible(false);
    ui->tableWidget->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.drawEllipse(200, 100, 24, 24);  //1
    painter.drawEllipse(100, 150, 24, 24);  //2
    painter.drawEllipse(300, 150, 24, 24);  //3

    painter.drawEllipse(200, 200, 24, 24);  //4
    painter.drawEllipse(100, 250, 24, 24);  //5
    painter.drawEllipse(300, 250, 24, 24);  //6

    painter.drawEllipse(200, 300, 24, 24);  //7
    painter.drawEllipse(100, 350, 24, 24);  //8
    painter.drawEllipse(300, 350, 24, 24);  //9

    painter.drawEllipse(200, 400, 24, 24);  //10

    LineFromCToC(200, 100, 200, 200, &painter);  //1  1-4
    LineFromCToC(200, 100, 100, 150, &painter);  //2  1-2
    LineFromCToC(200, 100, 300, 150, &painter);  //3  1-3
    LineFromCToC(100, 150, 100, 250, &painter);  //4  2-5
    LineFromCToC(100, 150, 200, 200, &painter);  //5  2-4
    LineFromCToC(200, 200, 100, 250, &painter);  //6  4-5
    LineFromCToC(300, 150, 300, 250, &painter);  //7  3-6
    LineFromCToC(200, 100, 300, 250, &painter);  //8  1-6
    LineFromCToC(200, 200, 300, 250, &painter);  //9  4-6
    LineFromCToC(200, 200, 200, 300, &painter);  //10 4-7
    LineFromCToC(100, 250, 200, 300, &painter);  //11 5-7
    LineFromCToC(300, 250, 200, 300, &painter);  //12 6-7
    LineFromCToC(100, 250, 100, 350, &painter);  //13 5-8
    LineFromCToC(200, 300, 100, 350, &painter);  //14 7-8
    LineFromCToC(100, 350, 200, 400, &painter);  //15 8-10
    LineFromCToC(300, 250, 300, 350, &painter);  //16 6-9
    LineFromCToC(200, 300, 300, 350, &painter);  //17 7-9
    LineFromCToC(100, 350, 300, 350, &painter);  //18 8-9
    LineFromCToC(300, 350, 200, 400, &painter);  //19 9-10

    painter.end();
}


