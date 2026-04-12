#include <bits/stdc++.h>
using namespace std;

int H, W;
char ch[ 110 ][ 110 ];
int a[ 110 ][ 110 ];
int Line[ 110 ], Row[ 110 ];

int main() {
    scanf( "%d%d", &H, &W );
    for( int i = 0; i < H; ++i ) scanf( "%s", ch[ i ] );
    for( int i = 0; i < H; ++i )
        for( int j = 0; j < W; ++j )
            a[ i ][ j ] = ( ch[ i ][ j ] == '.' ) ? 0 : 1;
    for( int i = 0; i < H; ++i ) {
        Line[ i ] = 1;
        for( int j = 0; j < W; ++j ) 
            if( a[ i ][ j ] ) {
                Line[ i ] = 0;
                break;
            }
    }
    for( int i = 0; i < W; ++i ) {
        Row[ i ] = 1;
        for( int j = 0; j < H; ++j ) 
            if( a[ j ][ i ] ) {
                Row[ i ] = 0;
                break;
            }
    }
    for( int i = 0; i < H; ++i ) {
    	if( Line[ i ] ) continue;
        for( int j = 0; j < W; ++j ) 
            if( Line[ i ] != 1 && Row[ j ] != 1 ) 
            	if( a[ i ][ j ] ) cout << "#"; else cout << ".";
        cout << endl;
    }
    return 0;
}