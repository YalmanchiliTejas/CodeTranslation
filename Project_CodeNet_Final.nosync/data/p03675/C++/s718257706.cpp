#include <bits/stdc++.h>

using namespace std ;

int main( void )
{

    int n ;

    cin >> n ;

    vector<int> v( n ) ;

    for( int i = 0 ; i < n ; i++ )  {

        cin >> v[i] ;

    }

    if( n == 1 )  {

        cout << v[0] ;
        return 0 ;

    }

    if( n % 2 == 0 )  {

        for( int i = n-1 ; i >= 0 ; i -= 2 )  {

        cout << v[i] << " " ;

        }

        for( int i = 0 ; i < n ; i += 2 )  {

            cout << v[i] << " " ;

        }

    }

    else  {

        for( int i = n-1 ; i >= 0 ; i -= 2 )  {

            cout << v[i] << " " ;

        }

        for( int i = 1 ; i < n ; i += 2 )  {

            cout << v[i] << " " ;

        }

    }

    return 0 ;

}
