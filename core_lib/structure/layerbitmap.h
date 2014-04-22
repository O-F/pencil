/*

Pencil - Traditional Animation Software
Copyright (C) 2005-2007 Patrick Corrieri & Pascal Naidon

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation;

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*/
#ifndef LAYERBITMAP_H
#define LAYERBITMAP_H

#include <QImage>
#include <QList>
#include <QString>
#include <QPainter>
#include "layerimage.h"
#include "bitmapimage.h"
#include "KeyFrame.h"

class LayerBitmap : public LayerImage
{
    Q_OBJECT

public:
    LayerBitmap( Object* object );
    ~LayerBitmap();

    // method from layerImage
    bool addNewKeyFrameAt( int frameNumber ) override;
    void loadImageAtFrame( QString, QPoint, int );

    QDomElement createDomElement( QDomDocument& doc );
    void loadDomElement( QDomElement element, QString dataDirPath );

    BitmapImage* getBitmapImageAtFrame( int frameNumber );
    BitmapImage* getLastBitmapImageAtFrame( int frameNumber, int increment );

private:
    QString fileName( int index );
    bool saveKeyFrame( KeyFrame*, QString strPath ) override;
};

#endif