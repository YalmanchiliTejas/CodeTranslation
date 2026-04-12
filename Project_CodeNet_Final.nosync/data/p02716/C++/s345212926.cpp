#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

ll dp[N][3][3], arr[N], n;

ll solve(int ind, int jmp, int odd)
{
    if(ind >= n) return -1e17 * (jmp == 2 or odd == 1);
    ll &ret = dp[ind][jmp][odd];
    if(~ret) return ret;
    ret = solve(ind + 2, jmp, !odd) + arr[ind];
    if(jmp) ret = max(ret, solve(ind + 1, jmp - 1, odd));
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%lld", &n);
    if(n == 1) return puts("0");
    for(int i = 0 ; i < n ; i++) scanf("%lld", arr + i);
    printf("%lld\n", solve(0, 1 + (n&1), (n/2)&1));
    return 0;
}
