#include <stdio.h>
#include <stdint.h>

///
/// C definition for structure node
/// index -- index of data element in the array
/// data -- value of element with index index in the array
///
typedef struct node_t
{
    int index;
    int data;
} node;

///
/// \brief partition --- all element less than pivot will stay left from pivot and all elements more then pivot will stay
/// right from pivot element; pivot is an element with index (beg + end)/2
/// \param array --
/// \param beg
/// \param end
/// \return
///
int partition( node* array, int beg, int end )
{
    int i = beg;
    int j = end;
    int pivot = array[ (i + j )/2 ].data;

    while( i <= j )
    {
        while( array[ i ].data <= pivot )
            ++i;

        while( array[ j ].data  > pivot )
            --j;

        if( i < j )
        {
            node tmp;

            tmp.index = array[ j ].index;
            tmp.data = array[ j ].data;

            array[ j ].index = array[ i ].index;
            array[ j ].data= array[ i ].data;

            array[ i ].index = tmp.index;
            array[ i ].data= tmp.data;

            ++i;
            --j;
        }
    }
}

///
/// \brief quick_sort
/// \param array -- pointer to the the array
/// \param beg -- index where array begins
/// \param end -- index where array ends
///
void quick_sort( node* array, int beg, int end )
{
    int i = beg;
    int j = end;
        int pivot = array[ (i + j )/2 ].data;

    do
    {
        while( (array[ i ].data < pivot ) && ( i < end ) )
            ++i;

        while( (array[ j ].data > pivot) && ( j > beg) )
            --j;

        if( i <= j )
        {

            node tmp;

            tmp.index = array[ j ].index;
            tmp.data = array[ j ].data;

            array[ j ].index = array[ i ].index;
            array[ j ].data= array[ i ].data;

            array[ i ].index = tmp.index;
            array[ i ].data= tmp.data;

            ++i;
            --j;

        }

    } while( i <= j );


    if( beg < j )
        quick_sort( array, beg, j );
    if( i < end )
        quick_sort( array, i, end );
}





int solution( int * A, int N )
{
    int result = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int s = 0;
    node* array_node = (node* ) malloc( N*sizeof( node ) );

    // Price N
    for (i = 0; i < N; i++)
    {
        array_node[  i ].index = i;
        array_node[ i ].data = A[ i ];
    }

    quick_sort( array_node, 0, N-1 );

    i = 0;
    j = 0;
    while( i < N )
    {
        j = i + 1;
        while( array_node[ i ].data == array_node[ j ].data )
           ++j;

        for( k = i; k < j; k++ )
        {
            for( s = i; s < j; s++ )
            {
                if( abs( array_node[ s ].index - array_node[ k ].index ) > result  )
                    result = abs( array_node[ s ].index - array_node[ k ].index );
            }
        }


        i = j;
    }

    free( array_node );

    return result;
}



int main(int argc, char *argv[])
{

    // Test 1
    {
        int A[ ] = { 4, 6, 2, 2, 6, 6, 1 };

        int i = solution( A, 7 );

        printf( " i = %d\n", i );
    }

    // Test 2
    {
        int A[ ] = { 6, 6, 2, 2, 6, 6, 1, 8, 2 };

        int i = solution( A, 9 );

        printf( " i = %d\n", i );
    }

    // Test 3
    {
        int A[ ] = { 6, 6, 6, 6 };

        int i = solution( A, 4 );

        printf( " i = %d\n", i );
    }

    // Test 4
    {
        int A[ ] = { 1,1,0,0,0,1,9,1,1,1 };

        int i = solution( A, 10 );

        printf( " i = %d\n", i );
    }

    // Test 5
    {
        int A[ ] = { 1 };

        int i = solution( A, 1 );

        printf( " i = %d\n", i );
    }

    return 0;
}

