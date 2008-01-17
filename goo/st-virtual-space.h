/*
 * st-virtual-space.h
 *
 * Copyright (C) 2008 Vincent Geddes <vgeddes@gnome.org>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __ST_VIRTUAL_SPACE__
#define __ST_VIRTUAL_SPACE__

#include <glib.h>

typedef struct _GooVirtualSpace GooVirtualSpace;

GooVirtualSpace *st_virtual_space_new (gsize size);

static inline char *
st_virtual_space_get_start (GooVirtualSpace * space)
{
    return space->start;
}

static inline char *
st_virtual_space_get_end (GooVirtualSpace * space)
{
    return space->end;
}

void st_virtual_space_destroy (GooVirtualSpace * space);


#endif /* __ST_VIRTUAL_SPACE__ */
