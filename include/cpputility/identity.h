//=================================================================================//
//                                                                                 //
//  cpputility                                                                     //
//                                                                                 //
//  Copyright (C) 2011-2016 Terry                                                  //
//                                                                                 //
//  This file is a portion of the cpputility. It is distributed under the MIT      //
//  License, available in the root of this distribution and at the following URL.  //
//  http://opensource.org/licenses/mit-license.php                                 //
//                                                                                 //
//=================================================================================//

#pragma once

#include <cstddef>

namespace utl
{

template<class T>
class identity
{
public:
	typedef typename std::size_t size_type;
	typedef typename T value_type;
	typedef typename T* pointer;
	typedef typename const T* const_pointer;
	typedef typename T& reference;
	typedef typename const T& const_reference;

public:
	static size_type value()
	{
		auto identity = m_next_identity;
		m_next_identity++;
		return identity;
	}

private:
	static size_type m_next_identity;
};

template<class T> identity<T>::size_type identity<T>::m_next_identity = 0;

class unique_identity : public identity<unique_identity>
{
public:
	typedef typename identity<unique_identity>::size_type size_type;
	typedef typename identity<unique_identity>::value_type value_type;
	typedef typename identity<unique_identity>::pointer pointer;
	typedef typename identity<unique_identity>::const_pointer const_pointer;
	typedef typename identity<unique_identity>::reference reference;
	typedef typename identity<unique_identity>::const_reference const_reference;

public:
	static size_type value()
	{
		return identity<unique_identity>::value();
	}
};

}