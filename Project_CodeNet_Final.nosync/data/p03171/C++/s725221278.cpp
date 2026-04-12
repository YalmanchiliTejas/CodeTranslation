#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 3001;
int n,a[3000],z,f[N][N];
bool cal[N][N];
int P[2];

int dp (int l, int r, int p)
{
    if (cal[l][r]) return f[l][r];
    if (l>r) return 0;
    if (p == 0)
    {
        f[l][r] = max(dp(l,r-1,1-p) + a[r], dp(l+1, r, 1-p) + a[l]);
    }
    else
    {
        f[l][r] = min(dp(l,r-1,1-p) - a[r], dp(l+1, r, 1-p) - a[l]);
    }
    cal[l][r] = true;
    return f[l][r];
}

signed main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << dp(0,n-1,0);
    return 0;
}
