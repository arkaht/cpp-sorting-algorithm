#include <iostream>
#include <vector>
#include <algorithm>

//  bubble sorting:
//	- best case: O(n)
//  - worst case: O(n²)
template <class T>
void bubble_sort( std::vector<T>& list ) 
{
	for ( int i = 0; i < list.size(); i++ )
	{
		printf( "iter %d\n", i );
		bool is_sorted = true;

		//  sort by pairs
		for ( auto itr = list.begin(); itr != list.end() - 1; itr++ )
		{
			auto next_itr = itr + 1;
			if ( *itr > *next_itr )
			{
				printf( "%d > %d: swapping\n", *itr, *next_itr );
				std::iter_swap( itr, next_itr );

				is_sorted = false;
			}
		}

		if ( is_sorted )
		{
			printf( "sorted\n" );
			break;
		}
	}
}

//  selection sorting:
//	- best case: O(n²)
//  - worst case: O(n²)
template <class T>
void selection_sort( std::vector<T>& list )
{
	for ( int i = 0; i < list.size(); i++ )
	{
		printf( "iter %d\n", i );

		auto itr = list.begin() + i;
		auto smallest_itr = itr;

		//  find smallest value
		for ( auto next_itr = itr; next_itr != list.end(); next_itr++ )
		{
			if ( *next_itr < *smallest_itr )
			{
				smallest_itr = next_itr;
			}
		}

		//  swap smallest w/ current
		if ( smallest_itr != itr )
		{
			printf( "%d > %d: swapping\n", *itr, *smallest_itr );
			std::iter_swap( itr, smallest_itr );
		}
	}
}


template <class T>
int quick_sort_partition( std::vector<T>& list, int from_id, int to_id )
{
	for ( int i = from_id; i <= to_id; ) 
	{
		//  move greater values to the right
		if ( list[i] > list[to_id] ) 
		{
			auto pivot = list.begin() + to_id;

			//  swap previous & pivot only if different from current
			if ( i != to_id - 1 ) 
			{
				std::iter_swap( pivot, pivot - 1 );
			}

			//  swap current & pivot
			std::iter_swap( list.begin() + i, pivot );

			to_id--;
		}
		//  increase index & stop on indexes equality
		else if ( i++ == to_id )
		{
			//printf( "partition ended at %d\n", to_id );
			return to_id;
		}
	}

	return to_id + 1;
}

//  quick sorting:
//  - best case O(n log(n))
//  - worst case O(n²)
template <class T>
void quick_sort( std::vector<T>& list, int from_id = 0, int to_id = -1 )
{
	//  auto-fill 'to_id'
	if ( to_id == -1 ) 
	{
		int size = list.size();
		to_id = size - 1;
	}
	if ( to_id <= from_id ) return;

	int pivot_id = quick_sort_partition( list, from_id, to_id );
	//printf( "%d to %d: %d\n", from_id, to_id, pivot_id );

	//  recursive partitioning
	quick_sort( list, from_id, pivot_id - 1 );
	quick_sort( list, pivot_id, to_id );
}