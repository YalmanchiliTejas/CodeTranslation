#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

int main()
{
    scanf( "%d%d", &n, &k );
    
    if( k == 0 ) {
    	printf( "%lld\n", ll(n) * n ); return 0;
	}
    
    ll ans = 0;
    for( int i = k+1; i <= n; i ++ )
    {
        ans += ( n / i ) * ( i - k );
        int tmp = ( n % i ) - k + 1; 
        if( tmp > 0 ) ans += tmp;
    }

    printf( "%lld\n", ans );

    return 0;
}