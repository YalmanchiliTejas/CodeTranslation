#include <bits/stdc++.h>
#define PREP(i, s, x) for(ll i = (s); i < (x); i++)
#define MREP(i, s, x) for(ll i = (s); i >= (x); i--)
#define REP(i, x) PREP(i, 0, x)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

// variable -------------------------------------------

constexpr ll INF = (1ll << 59);
constexpr ll MOD = 1000000007ll;

// structure ------------------------------------------

// function -------------------------------------------

// main -----------------------------------------------

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n){
		cin >> a[i];
	}

	//

	ll ans = 0;
	ll minisum = a[0];

	PREP(i, 1, n){
		ans += (minisum * a[i]) % MOD;
		ans %= MOD;
		minisum += a[i];
		minisum %= MOD;
	}

	cout << ans << endl;
	return 0;
}