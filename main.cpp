#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "CN_LR1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
//    QGraphicsScene scene;
//    scene.addText("HELLO WORLD!!!");

//    QGraphicsView view(&scene);
//    view.show();
    MainWindow w;
    w.setStyleSheet("MainWindow {background-color : white; color : black;}");
    w.show();

    return a.exec();
}
