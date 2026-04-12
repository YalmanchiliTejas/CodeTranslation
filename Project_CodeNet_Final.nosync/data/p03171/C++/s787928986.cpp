#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define inlld2(x, y) scanf("%lld%lld", &x, &y)
#define inlld3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define ind2(x, y) scanf("%d%d", &x, &y)
#define ind3(x, y, z) scanf("%d%d%d", &x, &y, &z)

const int N=3e3+5;
const int MOD=1e9+7;

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, arr[N], dp[N][N][2];

ll solve(ll i, ll j, ll mov)
{
    if(dp[i][j][mov]!=-1)
        return dp[i][j][mov];
    if(i==j && mov)
        return arr[i];
    else if(i==j)
        return -arr[i];
    if(mov)
        return dp[i][j][mov]=max(solve(i+1, j, 0)+arr[i], solve(i, j-1, 0)+arr[j]);
    else
        return dp[i][j][mov]=min(solve(i+1, j, 1)-arr[i], solve(i, j-1, 1)-arr[j]);
}

int main()
{
    inlld(n);
    for(ll a=1; a<=n; a++)
        inlld(arr[a]);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(1, n, 1));
    return 0;
}