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

////////////////////////////////////////////////////////////////////////////////
// internal header
////////////////////////////////////////////////////////////////////////////////

// composite types

#if defined(OS_WINDOWS)
	#include "Windows/composite_types.h"
#elif defined(OS_LINUX)
	#include "Linux/composite_types.h"
#else
	#error Error OS type!
#endif

// enumerator

#define BEGIN_ENUM(E)    struct E { \
	public: typedef E x; \
		explicit E(int value = 0) throw() : m_value(value) { } \
		E(const E& src) throw() : m_value(src.m_value) { } \
		E& operator=(const E& src) throw() { \
			if(this!=&src) { m_value = src.value; } return *this; } \
		E& operator=(int value) throw() \
			{ m_value = value; return *this; } \
		bool operator==(const E& src) const throw() \
			{ return m_value == src.m_value; } \
		bool operator==(int value) const throw() \
			{ return m_value == value; } \
		bool operator!=(const E& src) const throw() \
			{ return !operator==(src); } \
		bool operator!=(int value) const throw() \
			{ return !operator==(value); } \
		operator int() const throw() { return m_value; } \
		enum __Enum {
#define ENUM_ENTRY(name)      name,
#define ENUM_ENTRY(name, value)    name = (value),
#define END_ENUM()  }; private: int m_value; };

//function parameter

#define IN
#define OUT
#define INOUT

////////////////////////////////////////////////////////////////////////////////
