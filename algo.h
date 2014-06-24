/**********************************************\
*  no CopyRight reserved                       *
*  2014-4-24                                   *
*  YMK                                         *
***********************************************/

#pragma once

#include <algorithm>

namespace helper{

inline int HPLeft(int nPos)
{
	return (nPos << 1) + 1;
}

inline int HPRight(int nPos)
{
	return (nPos + 1) << 1;
}

inline int HPParent(int nPos)
{
	return (nPos - 1) >> 1;
}
}

template <class RandAccIter>
void MaxHeapify(RandAccIter start, int nHeapSize, int nPos)
{
	using namespace helper;

	int nLeft  = HPLeft(nPos);
	int nRight = HPRight(nPos);
	int nLargest = nPos;
	if (nLeft < nHeapSize && start[nLeft] > start[nPos])
	{
		nLargest = nLeft;
	}
	if (nRight < nHeapSize && start[nRight] > start[nLargest])
	{
		nLargest = nRight;
	}

	if (nLargest != nPos)
	{
		std::swap(start[nPos], start[nLargest]);
		MaxHeapify(start, nHeapSize, nLargest);
	}
}

template <class RandAccIter>
void BuildHeap(RandAccIter start, int nHeapSize)
{
	for (int ii = (nHeapSize >> 1) - 1; ii >= 0; --ii)
	{
		MaxHeapify(start, nHeapSize, ii);
	}
}

/**
*sort in ascending order
*/
template <class RandAccIter>
void HeapSort(RandAccIter start, RandAccIter finish)
{
	if (start == finish || start + 1 == finish)
	{
		return ;
	}
	int nHeapSize = std::distance(start, finish);
	BuildHeap(start, nHeapSize);
	for (int ii = nHeapSize - 1; ii >= 1; --ii)
	{
		swap(start[0], start[ii]);
		MaxHeapify(start, ii, 0);
	}
}
