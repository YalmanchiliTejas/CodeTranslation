#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main () {
    long long int n, k, i, j, ans, c1 ;
    scanf ( "%lld %lld", &n, &k ) ;
    ans = 0 ;
    for ( i = k ; i <= n ; i++ ) {
        if ( i == 0 ) {
            ans = n * n ;
            break ;
        }
        c1 = n / i ;
        ans += ( i - k ) * c1 ;
        j = n % ( c1 * i ) ;
        if ( j - k + 1 > 0 ) {
            ans += j - k + 1 ;
        }
    }
    printf ("%lld\n", ans ) ;
    return 0 ;
}
