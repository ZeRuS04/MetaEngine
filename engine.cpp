#include "engine.h"

Engine::Engine(const QString &hostName, const QString &user, const QString &pass, QObject *parent) :
    QObject(parent),
    hostName_(hostName),
    user_(user),
    pass_(pass)
{
    meta_db = QSqlDatabase::addDatabase("QMYSQL", "mydb");
    meta_db.setHostName(hostName_);
    meta_db.setDatabaseName("meta_db");
    meta_db.setUserName(user_);
    meta_db.setPassword(pass_);
    if(!meta_db.open())
    {
        setlogLine("Database meta_db could'n open\n");
        return;
    }
    setlogLine("Database meta_db open\n");
}


void Engine::getDatabases()
{
    QSqlQuery query;
    QString str("INSERT INTO server (hostname, user, pass) VALUES (%1,%2,%3);");
    str = str.arg(hostName_, user_, pass_);
    query.exec(str);

    query.exec("SHOW DATABASES;");
    while (query.next()) {
        QString name = query.value(0).toString();
        QSqlQuery subquery;
        subquery.exec();
                str("INSERT INTO database (hostname, user, pass) VALUES ()")
      }
}
