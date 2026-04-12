#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7 ;
long long n, arr[3009], X, Y;

long long mem[3009][3009][2];
long long solve( int i, int j, int turn ){
    if ( i > j ) return 0;
    long long& ret = mem[i][j][turn];
    if (~ret) return ret;
    if ( turn & 1 )
        return ret = max ( solve( i+1, j, !turn ) + arr[i] , solve( i, j-1, !turn ) + arr[j] );
    else
        return ret = min ( solve( i+1, j, !turn ) - arr[i] , solve( i, j-1, !turn ) - arr[j] );
}
int main(){
    memset( mem, -1, sizeof mem );
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; ++i )
        scanf("%d", arr+i);
    printf("%lld\n", solve(0,n-1,1));
}
