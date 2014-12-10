#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "engine.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Engine engi;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("engine", &engi);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
