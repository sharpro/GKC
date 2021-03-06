﻿/*
** Copyright (c) 2013, Xin YUAN, courses of Zhejiang University
** All rights reserved.
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the 2-Clause BSD License.
**
** Author contact information:
**   yxxinyuan@zju.edu.cn
**
*/

/*
This file contains basic classes.
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __GKC_BASE_H__
#define __GKC_BASE_H__
////////////////////////////////////////////////////////////////////////////////

#ifndef __GKC_DEF_H__
	#error GkcBase.h requires GkcDef.h to be included first.
#endif

////////////////////////////////////////////////////////////////////////////////
namespace GKC {
////////////////////////////////////////////////////////////////////////////////

//functions

//Swap
template <typename T>
inline void Swap(T& t1, T& t2)
{
	assert( &t1 != &t2 );
	T tmp = static_cast<T&&>(t1);
	t1 = static_cast<T&&>(t2);
	t2 = static_cast<T&&>(tmp);
}

template <>
inline void Swap<int>(int& t1, int& t2)
{
	assert( &t1 != &t2 );
	t1 ^= t2 ^= t1 ^= t2;
}

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif //__GKC_BASE_H__
////////////////////////////////////////////////////////////////////////////////
