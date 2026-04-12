#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "vector"
using namespace std;
#define MAXN 106
#define P 1000000007
int n;
int A[MAXN];
int Pow( int x , int a ) {
    int cur = x % P , ans = 1;
    while( a ) {
        if( a & 1 ) ans = 1ll * ans * cur % P;
        cur = 1ll * cur * cur % P , a >>= 1;
    }
    return ans;
}
pair<int,int> solve( int l , int r , int c ) {
//    cout << l << ' ' << r << endl;
    if( l > r ) return make_pair( 1 , 0 );
    int h = 0x3f3f3f3f;
    for( int i = l ; i <= r ; ++ i ) h = min( h , A[i] );
    vector<int> pos;
    pos.push_back( l - 1 );
    for( int i = l ; i <= r ; ++ i ) if( A[i] == h ) pos.push_back( i );
    pos.push_back( r + 1 );
    int nm = pos.size() - 2;
    int re = 1 , tot = 1;
    for( int i = 0 ; i < pos.size() - 1 ; ++ i ) {
        pair<int,int> ret = solve( pos[i] + 1, pos[i + 1] - 1, h );
        re = 1ll * re * ret.first % P , tot = 1ll * tot * ( ret.first + ret.second ) % P;
//        cout << l << ' ' << r << ' ' << pos[i] + 1 << ' ' << pos[i + 1] << ' ' << re << ' ' << tot << endl;
    }
    return make_pair( 1ll * re * Pow( 2 , h - c ) % P , ( 1ll * re * ( Pow( 2 , h - c ) - 2 ) % P + 1ll * Pow( 2 , nm ) * tot % P ) % P );
}
int main() {
    cin >> n;
    for( int i = 1 ; i <= n ; ++ i ) scanf("%d",&A[i]);
    cout << solve( 1 , n , 0 ).second << endl;
}