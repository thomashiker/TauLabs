/**
 ******************************************************************************
 *
 * @file       boardmanager.h
 * @author     The PhoenixPilot Team, Copyright (C) 2012.
 *             Parts by Nokia Corporation (qt-info@nokia.com) Copyright (C) 2009.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup CorePlugin Core Plugin
 * @{
 * @brief The Core GCS plugin
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include <QObject>

#include "core_global.h"
#include "mainwindow.h"
#include <coreplugin/iboardtype.h>


namespace Core {

class CORE_EXPORT BoardManager : public QObject
{
    Q_OBJECT

public:
    BoardManager();
    virtual ~BoardManager();

    void init();

    QList<IBoardType*> getAvailableBoardTypes() { return m_boardTypesList; }

    QList<int> getKnownVendorIDs();


protected:
//    void updateConnectionList(IConnection *connection);
//    void registerBoardType(IBoardType *board);

signals:
//    void availableDevicesChanged(const QLinkedList<Core::DevListItem> devices);

public slots:
//    void telemetryConnected();
//    void telemetryDisconnected();

private slots:
    // Two slots used to detect arrival/removal of board types
    // by plugins
    void objectAdded(QObject *obj);
    void aboutToRemoveObject(QObject *obj);

protected:
    QList<IBoardType*> m_boardTypesList;


private:

};

} //namespace Core
#endif // BOARDMANAGER_H
