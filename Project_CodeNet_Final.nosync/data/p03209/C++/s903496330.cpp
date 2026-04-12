#include <stdio.h>
#include <math.h>
//#include <algorithm>

static long long calc( long n, long long x )
{
    if(n==0) {
        return 1;
    }

    long long a = (long long)(pow( (double)2.0, (double)(n+2) ) - 3 + 0.1);
    if(x == a) {
        return (long long)(pow( (double)2.0, (double)(n+1)) - 1 + 0.1);
    }

    long long b = (long long)(pow( (double)2.0, (double)(n+1) ) - 3 + 0.1); 

    if(x==1) {
        return 0;
    }
    else if(x<=b+1) {
        return calc( n-1, x-1 );
    }
    else if(x==b+2) {
        return (1 + calc( n-1, b ) );
    }
    else if(x==b*2+3) {
        return (1 + 2 * calc( n-1, b ) );
    }
    else {
        return (1 + calc( n-1, b ) + calc( n-1, x-b-2));
    }

    return 1000000;
}

int main(int argc, char* argv[])
{
    long n;
    long long x;
    scanf("%ld %lld", &n, &x);

    long long ans = calc( n, x );

    printf("%lld\n", ans);

    return 0;
}

