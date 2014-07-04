#include <algorithm>
template <class RandAccIter>
int Partition(RandAccIter start, int nLeft, int nRight)
{
	typename RandAccIter::value_type value = start[nLeft];
	int nPos = nLeft;
	for (int ii = nLeft; ii <= nRight; ++ii)
	{
		if (start[ii] < value)
		{
			std::swap(start[ii], start[++nPos]);
		}
	}
	std::swap(start[nLeft], start[nPos]);
	return nPos;
}


template <class RandAccIter>
void QuickSort(RandAccIter start, int nStart, int nFinish)
{
	if (nStart >= nFinish)
	{
		return;
	}

	int nPos = Partition(start, nStart, nFinish);
	QuickSort(start, nStart, nPos - 1);
	QuickSort(start, nPos + 1, nFinish);
}


template <class RandAccIter>
void QuickSort(RandAccIter start, RandAccIter finish)
{
	int nSize = std::distance(start, finish);
	QuickSort(start, 0, nSize - 1);
}


template <class RandAccIter>
typename RandAccIter::value_type
FindNthMax(RandAccIter start, int nStart, int nFinish, int nPos)
{
	int nSplit = Partition(start, nStart, nFinish);
	if (nSplit == nPos)
	{
		return start[nSplit];
	}
	else if (nPos < nSplit)
	{
		return FindNthMax(start, nStart, nSplit - 1, nPos);
	}
	else
	{
		return FindNthMax(start, nSplit + 1, nFinish, nPos);
	}
}

template <class RandAccIter>
typename RandAccIter::value_type
FindNthMax(RandAccIter start, RandAccIter finish, int nPos)
{
	return FindNthMax(start, 0, std::distance(start, finish) - 1, nPos);
}
