#include <iostream>
#include <vector>
#include <cassert>

#include "sort.hpp"

std::vector<int> best_list { 1, 2, 3, 4, 5, 6, 7, 8 };
std::vector<int> worst_list { 8, 7, 6, 5, 4, 3, 2, 1 };
std::vector<int> random_list1 { 6, 7, 3, 8, 2, 5, 4, 1 };
std::vector<int> random_list2 { 5, 2, 8, 1, 4, 3, 7, 6 };

#define TEST_SORT( list, sort_func ) \
    std::cout << #list " - not sorted:" << std::endl;       \
    print_list( list );                                     \
                                                            \
    std::cout << #list " - " #sort_func ":" << std::endl;   \
    sort_func( list );                                      \
    print_list( list );                                     \
                                                            \
    assert( is_sorted( list ) )

bool is_sorted( const std::vector<int>& list )
{
    for ( int i = 0; i < list.size() - 1; i++ )
    {
        if ( list[i] > list[i + 1] )
        {
            return false;
        }
    }

    return true;
}

void print_list( const std::vector<int>& list )
{
    for ( int i = 0; i < list.size(); i++ )
    {
        std::cout << "[" << i << "]: " << list[i] << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    //  bubble sort
    TEST_SORT( best_list, bubble_sort );
    TEST_SORT( worst_list, bubble_sort );
    TEST_SORT( random_list1, bubble_sort );
    TEST_SORT( random_list2, bubble_sort );

    //  selection sort
    /*TEST_SORT( best_list, selection_sort );
    TEST_SORT( worst_list, selection_sort );
    TEST_SORT( random_list1, selection_sort );
    TEST_SORT( random_list2, selection_sort );*/

    //  quick sort
    /*TEST_SORT( best_list, quick_sort );
    TEST_SORT( worst_list, quick_sort );
    TEST_SORT( random_list1, quick_sort );
    TEST_SORT( random_list2, quick_sort );*/
}
