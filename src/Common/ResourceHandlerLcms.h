/*
 * This file is a part of LuminanceHDR package.
 * ----------------------------------------------------------------------
 * Copyright (C) 2012 Davide Anastasia
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * ----------------------------------------------------------------------
 */

#ifndef RESOURCEHANDLERLCMS_H
#define RESOURCEHANDLERLCMS_H

//! \file ResourceHandlerLcms.h
//! \brief This file contains simple resource handlers for LCMS2 library
//! \author Davide Anastasia <davideanastasia@users.sourceforge.net>
//! \date 2012 05 05
//! \since 2.3.0-beta1

#include "ResourceHandler.h"

#include <lcms2.h>
#ifdef QT_DEBUG
#include <QDebug>
#endif

struct CleanUpCmsProfile
{
    static inline
    void cleanup(cmsHPROFILE profile)
    {
        if ( profile )
        {
#ifdef QT_DEBUG
            qDebug() << "CleanUpCmsProfile::cleanup()";
#endif
            cmsCloseProfile(profile);
        }
    }
};
typedef ResourceHandler<void, CleanUpCmsProfile> ScopedCmsProfile;
// typedef ResourceHandler<void, CleanUpCmsProfile> ScopedCmsProfile;

struct CleanUpCmsTransform
{
    static inline
    void cleanup(cmsHTRANSFORM transform)
    {
        if ( transform )
        {
#ifdef QT_DEBUG
            qDebug() << "CleanUpCmsTransform::cleanup()";
#endif
            cmsDeleteTransform(transform);
        }
    }
};
typedef ResourceHandler<void, CleanUpCmsTransform> ScopedCmsTransform;
//typedef QScopedPointer<char, CleanUpCmsTransform> ScopedCmsTransformV2;

#endif
