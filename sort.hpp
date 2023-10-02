#include <iostream>
#include <vector>
#include <algorithm>

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

template <class T>
void selection_sort( std::vector<T>& list )
{
	for ( int i = 0; i < list.size(); i++ )
	{
		printf( "iter %d\n", i );

		auto itr = list.begin() + i;
		auto smallest_itr = itr;
		//bool is_sorted = true;

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
			//is_sorted = false;
		}

		/*if ( is_sorted )
		{
			printf( "sorted\n" );
			break;
		}*/
	}
}

template <class T>
void quick_sort( std::vector<T>& list )
{
	
}