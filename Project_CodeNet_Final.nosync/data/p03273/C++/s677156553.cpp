#include <bits/stdc++.h>

using namespace std ;

int a , b ;

int main ()
{
    cin >> a >> b ;
    char c [ a * b ] ;
    int d [ a ] , e [ b ] , cnt1 = 0 , cnt2 = 0 ;
    for ( int i = 0 ; i < a * b ; ++ i ){
        cin >> c [ i ] ;
    }
    for ( int i = 0 ; i < a ; ++ i ){
        for ( int j = 0 ; j < b ; ++ j ){
            if ( c [ b * i + j ] == '#' ){
                d [ cnt1 ] = i ;
                cnt1 ++ ;
                break ;
            }
        }
    }
    for ( int j = 0 ; j < b ; ++ j ){
        for ( int i = 0 ; i < a ; ++ i ){
            if ( c [ b * i + j ] == '#' ){
                e [ cnt2 ] = j ;
                cnt2 ++ ;
                break ;
            }
        }
    }
    for ( int i = 0 ; i < cnt1 ; ++ i ){
        for ( int j = 0 ; j < cnt2 ; ++ j ){
            cout << c [ b * d [ i ] + e [ j ] ] ;
        }
        cout << endl ;
    }
}
