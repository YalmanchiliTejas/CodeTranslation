#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;
const ll mod = (ll)1e9+7;
const int INF = 0x3f3f3f3f;
ll max(ll a, ll b){return a > b ? a : b;}
ll min(ll a, ll b){return a < b ? a : b;}

ll dp[3001][3001];
ll a[3001];

ll R(int i, int j)
{
    if(dp[i][j]) return dp[i][j];
    if(i==j) return a[i];
    ll c = a[i] - R(i+1, j);
    ll d = a[j] - R(i, j-1);
    dp[i][j] = max(c, d);
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll ans = R(1, n);
    cout << ans;
}

