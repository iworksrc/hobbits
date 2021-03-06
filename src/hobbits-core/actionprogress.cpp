#include "actionprogress.h"
#include <QMutexLocker>

ActionProgress::ActionProgress(QObject *parent) :
    QObject(parent),
    m_progressPercent(0),
    m_cancelled(0)
{

}

void ActionProgress::setProgressPercent(int progressPercent)
{
    QMutexLocker locker(&m_mutex);

    m_progressPercent = progressPercent;
    emit progressPercentChanged(m_progressPercent);
}

void ActionProgress::setCancelled(bool cancelled)
{
    QMutexLocker locker(&m_mutex);

    m_cancelled = cancelled;
}

bool ActionProgress::getCancelled()
{
    QMutexLocker locker(&m_mutex);

    return m_cancelled;
}
