/*
 * avr-gcc lacks C++ standard library. I need some
 * things form this library so I copied them here.
 */

// Copyright (C) 2008, 2009, 2010 Free Software Foundation, Inc.
//
// This file is part of GCC.
//
// GCC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// GCC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

#ifndef FORWARD_H_INCLIUDED
#define FORWARD_H_INCLIUDED

namespace std {

#include "type_traits"

/// forward (as per N3143)
template<typename _Tp>
    inline _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t) 
    { return static_cast<_Tp&&>(__t); }

template<typename _Tp>
    inline _Tp&&
    forward(typename std::remove_reference<_Tp>::type&& __t) 
    {
      static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument"
		    " substituting _Tp is an lvalue reference type");
      return static_cast<_Tp&&>(__t);
    }
    
} // namespace std

#endif // FORWARD_H_INCLIUDED
