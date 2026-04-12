#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a.size())
#define clr(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for(int i=(int)(a); i<(int)(b); ++i)
#define REPD(i, a, b) for(int i=(int)(a)-1; i>=(int)(b); --i)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5, MOD = 1e9 + 7;
int n;
ll a[N];

ll add(ll aa, ll b) {
	while(aa < 0) aa += MOD;
	while(b < 0) b += MOD;
	return (aa % MOD + b % MOD) % MOD;
}

ll mul(ll aa, ll b) {
	while(aa < 0) aa += MOD;
	while(b < 0) b += MOD;
	b %= MOD;
	aa %= MOD;
	return (aa * b) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << (int)1e9 << endl;
    cin >> n;
    ll tot = 0;
    REP(i, 0, n) {
    	cin >> a[i];
    	tot += a[i];
    }
    ll res = 0;
    REP(i, 0, n) {
    	res = add(res, mul(a[i], (tot - a[i])));
    	tot -= a[i];
    }
    cout << res << "\n";
    return 0;
}
