#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e3+5;
const int MAXNN = 1e5+7;
const int INF = 1e9+7;
#define ll long long
#define pb push_back
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F first
#define S second

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll MOD(ll a){
    return ((a%INF)+INF)%INF;
}

ll inv(ll a){
    return poww(a,INF-2,INF);
}

ll dp[MAXN][MAXN][2],a[MAXN];

int main()
{
    fast_io;
    //cout << fixed << setprecision(15);

    int n;cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    for(int l=n;l>=1;--l){
        for(int r=l;r<=n;++r){
            dp[l][r][0] = max(dp[l+1][r][1] + a[l],dp[l][r-1][1] + a[r]);
            dp[l][r][1] = min(dp[l+1][r][0] - a[l],dp[l][r-1][0] - a[r]);
        }
    }
    cout << dp[1][n][0];
}
