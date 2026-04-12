#include <bits/stdc++.h>
using namespace std;

long long dp[3001][3001];
long long nCr[3001][3001];
long long x[3001];
int n; long long m;

long long gopp(long long x, long long y, long long z){
    long long ret = 1;
    long long gop = x % z;
    while(y){
        if(y & 1LL) ret = (ret * gop) % z;
        gop = (gop * gop) % z;
        y /= 2;
    }
    return ret;
}

int main(){
    scanf("%d%lld",&n,&m);
    dp[0][0] = 1;
    nCr[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
        nCr[i][0] = 1;
        for(int j=1;j<=i;j++){
            dp[i][j] = (dp[i-1][j-1] + (dp[i-1][j] * (j+1))) % m;
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % m;
        }
    }
    long long ans = 0;
    for(int i=0;i<=n;i++){
        long long sum = 0;
        for(int j=0;j<=i;j++){
            long long cal = gopp(2LL, ((long long)j * (long long)(n - i)), m);
            dp[i][j] = (dp[i][j] * cal) % m;
            sum = (sum + dp[i][j]) % m;
        }
        long long cal2 = gopp(2LL, gopp(2LL, n-i, m-1), m);
        sum = (sum * cal2) % m;
        sum = (sum * nCr[n][i]) % m;
        if(i%2 == 1) sum = (m - sum) % m;
        ans = (ans + sum) % m;
    }
    printf("%lld\n", ans);
}
