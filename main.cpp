#include <iostream>
#include <vector>

#include "sort.hpp"

std::vector<int> list1 { 6, 7, 3, 8, 2, 5, 4, 1 };
std::vector<int> list2 { 8, 7, 6, 5, 4, 3, 2, 1 };
std::vector<int> list3 { 1, 2, 3, 4, 5, 6, 7, 8 };

#define PRINT_SORT( list, sort_func ) \
    std::cout << #list " - not sorted:" << std::endl; \
    print_list( list ); \
    std::cout << #list " - " #sort_func ":" << std::endl; \
    sort_func( list ); \
    print_list( list )

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
    //PRINT_SORT( list1, bubble_sort );
    //PRINT_SORT( list2, bubble_sort );
    //PRINT_SORT( list3, bubble_sort );

    PRINT_SORT( list1, selection_sort );
    PRINT_SORT( list2, selection_sort );
    PRINT_SORT( list3, selection_sort );

    //PRINT_SORT( list1, quick_sort );
    //PRINT_SORT( list2, quick_sort );
    //PRINT_SORT( list3, quick_sort );
}
