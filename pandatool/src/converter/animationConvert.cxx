// Filename: animationConvert.cxx
// Created by:  drose (21Jan03)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://www.panda3d.org/license.txt .
//
// To contact the maintainers of this program write to
// panda3d@yahoogroups.com .
//
////////////////////////////////////////////////////////////////////

#include "animationConvert.h"

#include "string_utils.h"
#include "notify.h"

////////////////////////////////////////////////////////////////////
//     Function: format_animation_convert
//  Description: Returns the string corresponding to this method.
////////////////////////////////////////////////////////////////////
string
format_animation_convert(AnimationConvert convert) {
  switch (convert) {
  case AC_invalid:
    return "invalid";

  case AC_none:
    return "none";

  case AC_flip:
    return "flip";
  }
  nout << "**unexpected AnimationConvert value: (" << (int)convert << ")**";
  return "**";
}

////////////////////////////////////////////////////////////////////
//     Function: AnimationConvert output operator
//  Description:
////////////////////////////////////////////////////////////////////
ostream &
operator << (ostream &out, AnimationConvert convert) {
  return out << format_animation_convert(convert);
}

////////////////////////////////////////////////////////////////////
//     Function: string_animation_convert
//  Description: Converts from a string, as might be input by the
//               user, to one of the known AnimationConvert types.
//               Returns AC_invalid if the string is unknown.
////////////////////////////////////////////////////////////////////
AnimationConvert
string_animation_convert(const string &str) {
  if (cmp_nocase(str, "none") == 0) {
    return AC_none;

  } else if (cmp_nocase(str, "flip") == 0) {
    return AC_flip;

  } else {
    return AC_invalid;
  }
}
