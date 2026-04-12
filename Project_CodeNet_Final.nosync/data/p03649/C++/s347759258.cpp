#include<cstdio>

typedef long long int lli;

int main(void) {
    int n;
    lli a[50];

    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);

    lli e=60 * (10000000000000000LL);
    lli b=-1;

    while(e-b > 1) {
        lli m = (e+b)/2;

        lli res=0;
        for(int i=0; i<n; i++) {
            lli now = a[i] + m;
            res += (now-(n-1) + n) / (n+1);
        }

        if(res <= m)
            e = m;
        else
            b = m;
    }

    lli k;
    for(k=e-1000; k<e+1000; k++) {
        lli m = k;
        lli res = 0;
        for(int i=0; i<n; i++) {
            lli now = a[i] + m;
            res += (now-(n-1) + n) / (n+1);
        }
        if(res <= m)
            break;
    }

    printf("%lld\n", k);

    return 0;
}
