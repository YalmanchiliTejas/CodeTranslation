#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd( ll x, ll y );
ll lcm( ll x, ll y );

int data[128] = {};

int main()
{
    int x;
    int cnt = 0;

    for ( int i = 0; i < 12; ++i ) {
        scanf("%d", &x );
        data[x]++;
    }

    for ( int i = 1; i <= 100; ++i ) {
        if ( data[i] % 4 == 0 ) {
            cnt += data[i] / 4;
        }
    }

    if ( cnt == 3 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

ll gcd( ll x, ll y )
{
    if ( y == 0 ) return x;
    return gcd( y, x % y );
}

ll lcm( ll x, ll y )
{
    return x / gcd( x, y ) * y;
}


