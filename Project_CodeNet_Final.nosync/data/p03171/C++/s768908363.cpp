#include <bits/stdc++.h>

#define Solved int main()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define forn(i, n) for(int i = 1; i <= n; i++)
#define rep(i, x, y) for(int i = x; i <= y; i++)
#define sz(x) (int)x.size()
#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define ld long double
#define mii map<int, int>
#define all(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound
using namespace std;

inline ll bip(ll x,ll n,ll mod){ll res=1;while(n){if(n&1){res=(res*x)%mod;}x=(x*x)%mod;n>>=1;}return res;}

const int maxn = 1e9;
const ll inf = 1e18;
//const int mod = 998244353;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

int n, a[3011];
ll sum[3011], dp[3011][3010];

ll rec(int l, int r, int pl) {
    if (l > r) return 0;
    if (dp[l][r]) return dp[l][r];

    ll v1 = a[l] + (sum[r] - sum[l] - rec(l + 1, r, 3 - pl));
    ll v2 = a[r] + (sum[r - 1] - sum[l - 1] - rec(l, r - 1, 3 - pl));
    return dp[l][r] = max(v1, v2);
}

void solve() {
    cin >> n;

    forn (i, n)
        cin >> a[i];

    sum[1] = a[1];
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];

    ll X = rec(1, n, 1);
    cout << X - (sum[n] - X);
}

Solved {
    SpeedForce;
	int tt = 1;
    //cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	}

}
