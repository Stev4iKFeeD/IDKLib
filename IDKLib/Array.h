#pragma once

#include "IDKDefines.h"
#include "IDKTypes.h"

IDK_NAMESPACE_BEGIN

template <typename Type, uint32 size>
class Array
{
public:
	Array() = default;
	Array(const Array& other);

	~Array() = default;

	Array& operator=(const Array& other);

	Type& operator[](uint32 i);
	const Type& operator[](uint32 i) const;

	FORCEINLINE constexpr uint32 GetSize() const { return size; }

private:
	Type allocator[size];

	void CopyValuesFrom(const Array& other);
};

template <typename Type, uint32 size>
Array<Type, size>::Array(const Array& other)
{
	CopyValuesFrom(other);
}

template <typename Type, uint32 size>
Array<Type, size>& Array<Type, size>::operator=(const Array& other)
{
	if (this != &other)
	{
		CopyValuesFrom(other);
	}

	return *this;
}

template <typename Type, uint32 size>
Type& Array<Type, size>::operator[](uint32 i)
{
	// TODO: out of range exception

	return allocator[i];
}

template <typename Type, uint32 size>
const Type& Array<Type, size>::operator[](uint32 i) const
{
	// TODO: out of range exception

	return allocator[i];
}

template <typename Type, uint32 size>
void Array<Type, size>::CopyValuesFrom(const Array& other)
{
	for (uint32 i = 0; i < size; ++i)
	{
		allocator[i] = other.allocator[i];
	}
}

IDK_NAMESPACE_END
