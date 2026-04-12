#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 2e5 + 5, M = 2 * N + 5;

int n, a[N];
ll dp[N][3];

ll solve(int i, int rem){
    if(i >= n)return rem == 2 ? -1e17 : 0;
    ll &ret = dp[i][rem];
    if(~ret)return ret;
    ret = -1e17;
    ret = max(ret, solve(i + 2, rem) + a[i]);
    if(rem)
        ret = max(ret, solve(i + 1, rem - 1));
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d", a + i);
    memset(dp, -1 , sizeof dp);
    printf("%lld\n", solve(0, (n & 1) + 1));
}