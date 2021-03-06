/* poppler-media.h: glib interface to MediaRendition
 *
 * Copyright (C) 2010 Carlos Garcia Campos <carlosgc@gnome.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __POPPLER_MEDIA_H__
#define __POPPLER_MEDIA_H__

#include <glib-object.h>
#include "poppler.h"

G_BEGIN_DECLS

#define POPPLER_TYPE_MEDIA                   (poppler_media_get_type ())
#define POPPLER_MEDIA(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), POPPLER_TYPE_MEDIA, PopplerMedia))
#define POPPLER_IS_MEDIA(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), POPPLER_TYPE_MEDIA))

// FIXME: this should be generic (PopplerSaveFunc)
typedef gboolean (*PopplerMediaSaveFunc) (const gchar  *buf,
					  gsize         count,
					  gpointer      data,
					  GError      **error);

GType        poppler_media_get_type         (void) G_GNUC_CONST;
gboolean     poppler_media_is_embedded      (PopplerMedia        *media);
const gchar *poppler_media_get_filename     (PopplerMedia        *media);
const gchar *poppler_media_get_mime_type    (PopplerMedia        *media);
gboolean     poppler_media_save             (PopplerMedia        *media,
					     const char          *filename,
					     GError             **error);
gboolean     poppler_media_save_to_callback (PopplerMedia        *media,
					     PopplerMediaSaveFunc save_func,
					     gpointer             user_data,
					     GError             **error);

G_END_DECLS

#endif /* __POPPLER_MEDIA_H__ */

