#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3000;

int n, arr[MAXN+10];
ll dp[MAXN+10][MAXN+10];

ll solve(int l, int r)
{
    if(l>r) return 0;

    bool turn=((r-l+1)%2==n%2);
    ll &ret=dp[l][r];
    if(ret!=-1) return ret;

    if(turn)
    {
        ret=max(solve(l+1, r)+arr[l], solve(l, r-1)+arr[r]);
    }
    else
    {
        ret=min(solve(l+1, r)-arr[l], solve(l, r-1)-arr[r]);
    }

    return ret;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int i, j;

    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &arr[i]);

    printf("%lld", solve(1, n));
    return 0;
}
