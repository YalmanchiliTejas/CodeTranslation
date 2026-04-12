#include <iostream>

using namespace std ;

int main ()
{
    int n , maxH , cnt ;
    int arr [ 20 ] ;
    while ( cin >> n )
    {
        maxH = 0 ; cnt = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            cin >> arr[ i ] ;
            if ( arr [ i ] >= maxH )
            {
                maxH = arr [ i ] ;
                cnt ++ ;
            }
        }
        cout << cnt << endl ;
    }
}
