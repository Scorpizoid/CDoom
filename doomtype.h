// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//	Simple basic typedefs, isolated here to make it easier
//	 separating modules.
//    
//-----------------------------------------------------------------------------


#ifndef __DOOMTYPE__
#define __DOOMTYPE__

#include <sdl.h> //!!

//#define EPOC_DEBUG_PRINT //!!

#ifndef __BYTEBOOL__
#define __BYTEBOOL__
// Fixed to use builtin bool type with C++.
#ifdef __cplusplus
typedef bool boolean;
#else
#ifdef __BEOS__	/* boolean is a builtin type for MWCC */
#define boolean D_BOOL
#undef false
#define false D_false
#undef true
#define true D_true
#endif
typedef enum {false, true} boolean;
#endif
typedef unsigned char byte;
#endif


// Predefined with some OS.
#ifdef LINUX
#include <values.h>
#else
#ifndef MAXCHAR
#define MAXCHAR		((char)0x7f)
#endif
#ifndef MAXSHORT
#define MAXSHORT	((short)0x7fff)
#endif

// Max pos 32-bit int.
#ifndef MAXINT
#define MAXINT		((int)0x7fffffff)	
#endif
#ifndef MAXLONG
#define MAXLONG		((long)0x7fffffff)
#endif
#ifndef MINCHAR
#define MINCHAR		((char)0x80)
#endif
#ifndef MINSHORT
#define MINSHORT	((short)0x8000)
#endif

// Max negative 32-bit integer.
#ifndef MININT
#define MININT		((int)0x80000000)	
#endif
#ifndef MINLONG
#define MINLONG		((long)0x80000000)
#endif
#endif


//!!
#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
#  define __attribute__(Spec) /* empty */
# endif
#endif

//!!
#ifndef ATTRIBUTE_PACKED
# define ATTRIBUTE_PACKED //!!__attribute__ ((packed))
#endif

//!!
#ifndef ATTRIBUTE_PACKED2
# define ATTRIBUTE_PACKED2 __attribute__ ((packed))
#endif

//!!
#ifndef EPOC_DEBUG_PRINT
#undef SDL_TRACE 
#define SDL_TRACE(error_str) 
#undef SDL_TRACE1
#define SDL_TRACE1(error_str, param) 
#undef SDL_MEM
#define SDL_MEM() 
#endif

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
