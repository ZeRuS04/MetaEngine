#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QSqlDatabase>

class Engine : public QObject
{
    Q_OBJECT
    QString m_logLine;
    QSqlDatabase meta_db;
    QSqlDatabase current_db;

    QString hostName_;
    QString user_;
    QString pass_;



public:
    explicit Engine(QObject *parent = 0);
    Q_PROPERTY(QString logLine READ logLine NOTIFY logLineChanged)


    void getDatabases();
    QString logLine() const
    {
        return m_logLine;
    }

signals:

void logLineChanged(QString arg);

public slots:

    void setlogLine(QString arg)
    {
        if (m_logLine != arg) {
            m_logLine = arg;
            emit logLineChanged(arg);
        }
    }
};

#endif // ENGINE_H
