/*
 * AT-SPI - Assistive Technology Service Provider Interface
 * (Gnome Accessibility Project; http://developer.gnome.org/projects/gap)
 *
 * Copyright 2001, 2002 Sun Microsystems Inc.,
 * Copyright 2001, 2002 Ximian, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <cspi/spi.h>
#include <cspi/spi-private.h>


/**
 * AccessibleDocument_ref:
 * @obj: a pointer to the #AccessibleDocument object on which to operate.
 *
 * Increment the reference count for an #AccessibleDocument object.
 **/
void
AccessibleDocument_ref (AccessibleDocument *obj)
{
  cspi_object_ref (obj);
}

/**
 * AccessibleDocument_unref:
 * @obj: a pointer to the #Accessible object on which to operate.
 *
 * Decrement the reference count for an #AccessibleDocument object.
 **/

void
AccessibleDocument_unref (AccessibleDocument *obj)
{
  cspi_object_unref (obj);
}


char *
AccessibleDocument_getLocale (AccessibleDocument *obj)
{
  char *retval = "C";

  cspi_return_val_if_fail (obj != NULL, "C");

  retval = Accessibility_Document_getLocale (CSPI_OBJREF (obj),
					     cspi_ev ());
  
  cspi_return_val_if_ev ("getLocale", NULL);

  return retval;

}

char *
AccessibleDocument_getAttributeValue (AccessibleDocument *obj,
				      char *attribute)
{
  
  char *retval;

  cspi_return_val_if_fail (obj != NULL, NULL);

  retval = Accessibility_Document_getAttributeValue (CSPI_OBJREF (obj),
						     attribute,
						     cspi_ev ());

  cspi_return_val_if_ev ("getAttributeValue", NULL);

  return retval;
  
}
				      

AccessibleAttributeSet * 
AccessibleDocument_getAttributes (AccessibleDocument *obj){

  AccessibleAttributeSet *retval;

  cspi_return_val_if_fail (obj != NULL, NULL);

  retval = Accessibility_Document_getAttributes (CSPI_OBJREF (obj),
						    cspi_ev ());
  cspi_return_val_if_ev ("getAttributes", NULL);
  
  return retval;

}
