/* Copyright (C) 2017 Benjamin Isbarn.

   This file is part of BeneOverlay.

   BeneOverlay is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   BeneOverlay is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with BeneOverlay.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DATAREFMANAGER_H
#define DATAREFMANAGER_H

#include <QObject>
#include <QHash>
#include <QVariant>
#include <QVector>

class DataRef;

class DataRefManager : public QObject
{
    Q_OBJECT
public:
    explicit DataRefManager(QObject *parent = 0);

    Q_INVOKABLE QObject *getDataRef(QString const &name);

    QHash<QString, QObject *> dataRefMap();

private:
    QHash<QString, QObject*> data_ref_map_;
    QHash<QString, QList<QVariant>> airports_;

    QVector<int> fps_buffer_;

public slots:
    void loadDataRefs();
    void saveDataRefs();
    void setFPS(int fps);

private slots:
    void calcRouteDistance();
    void calcDistanceToDestination();
    void calcETA();
    void updateFPSBufferSize();
};

#endif // DATAREFMANAGER_H