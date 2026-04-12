
#include "bits/stdc++.h"
using namespace std;
long long Mod = 1000000007;
long long Fact[200005] , InvFact[200005];

long long Power( long long base , int e ){
    if( e == 0 ) return 1LL;
    else{
        long long middle = Power( base , e >> 1 );
        if( e & 1 ) return ( ( ( middle * middle ) % Mod ) * base ) % Mod; 
        else return ( middle * middle ) % Mod;
    }
}

void PreProcess( int N ){
    Fact[0] = 1;
    InvFact[0] = Power( Fact[0] , Mod - 2 );

    for( int i = 1 ; i <= N ; ++i ){
        Fact[i] = ( Fact[i - 1] * i ) % Mod;
        InvFact[i] = Power( Fact[i] , Mod - 2 );
    }
}

int main(){
    int N , M , k , i , j;
    scanf( "%d%d%d" , &N , &M , &k );
    PreProcess( N * M );
    long long Ans = 0;
    long long Stan = ( ( ( Fact[N * M - 2] * InvFact[k - 2] ) % Mod ) * InvFact[N * M - k] ) % Mod; 
    long long row , col;

    for( i = 1 ; i <= N ; ++i ){
        for( j = 1 ; j <= M ; ++j ){
            row = ( M * ( ( ( ( ( i - 1LL ) * i ) / 2LL ) % Mod + ( ( ( N - i ) * ( N - i + 1LL ) ) / 2LL ) % Mod ) % Mod ) ) % Mod;
            col = ( N * ( ( ( ( ( j - 1LL ) * j ) / 2LL ) % Mod + ( ( ( M - j ) * ( M - j + 1LL ) ) / 2LL ) % Mod ) % Mod ) ) % Mod;
            Ans = ( Ans + row + col ) % Mod;
        }
    }

    Ans = ( Ans * Stan ) % Mod; 
    Ans = ( Ans * Power( 2 , Mod - 2 ) ) % Mod;
    printf( "%lld\n" , Ans );
    return 0;
}