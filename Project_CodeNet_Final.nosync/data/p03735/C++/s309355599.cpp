#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<unordered_map>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;

vector < pair < int , int > > srt ;

int cnt[ MAXN ] ;
int sm = 0 ;


long long f ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    int sz = srt.size ( ) ;
    int en = -1 ;
    int sm = 0 ;
    long long mnint = -1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( en < i ) {
            ++ cnt[ srt[ i ].second ] ;
            ++ sm ;
            en = i ;
        }
        while ( en < sz - 1 && sm < n ) {
            ++ en ;
            ++ cnt[ srt[ en ].second ] ;
            if ( cnt[ srt[ en ].second ] == 1 ) { ++ sm ; }
        }
        if ( sm == n ) {
            long long sr = srt[ en ].first - srt[ i ].first ;
            if ( mnint < 0 || mnint > sr ) { mnint = sr ; }
        }
        -- cnt[ srt[ i ].second ] ;
        if ( cnt[ srt[ i ].second ] == 0 ) { -- sm ; }
    }
    return mnint * ( srt[ sz - 1 ].first - srt[ 0 ].first ) ;
}

long long obtain ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    int sz = srt.size ( ) ;
    long long fst = -1 ;
    long long lst = -1 ;
    int sm = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( cnt[ srt[ i ].second ] > 0 ) {
            if ( fst == -1 ) { fst = srt[ i ].first ; }
        }
        else {
            cnt[ srt[ i ].second ] = 1 ;
            ++ sm ;
            if ( sm == n ) { lst = srt[ i ].first ; }
        }
        if ( sm == n && fst > -1 ) { break ; }
    }
    return ( lst - srt[ 0 ].first ) * ( srt[ sz - 1 ].first - fst ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        srt.push_back ( { a[ i ].first , i } ) ;
        srt.push_back ( { a[ i ].second , i } ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
}

void solve ( ) {
    if ( n == 1 ) {
        printf ( "0\n" ) ;
        return ;
    }
    int sz = srt.size ( ) ;
    long long ans = obtain ( ) ;
    if ( srt[ sz - 1 ].second != srt[ 0 ].second ) {
        ans = min ( ans , f ( ) ) ;
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
