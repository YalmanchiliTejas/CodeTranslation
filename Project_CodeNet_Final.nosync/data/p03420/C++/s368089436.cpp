#include<cstdio>


typedef long long int lli;

int main(void) {
    int n,k;
    scanf("%d%d",&n,&k);

    lli res = 0;

    if(k==0) {
        res = n;
        res*= res;
        printf("%lld\n", res);
        return 0;
    }
    // 1 <= a = r + lb <= n
    // 1 <= lb <= n-r
    for(int b=k+1; b<=n; b++) {
        lli t = n/b * (b-k);
        res += t;
        lli l = n - n/b*b;
        if(l>=k) res += l-k+1;
        //printf("%d %d %d\n", b, t, l-k+1);
    }

    printf("%lld\n", res);
}