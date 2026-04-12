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
	ll n, x, m;
	cin >> n >> x >> m;

	vector<ll> memo;
	vector<ll> a;
	ll len = 0;
	a.push_back(0);
	a.push_back(x);
	memo.push_back(0);
	memo.push_back(x);
	unordered_set<ll> st;

	ll nandakke = -1;
	ll dokodatta = -1;

	ll ans = 0;
	PREP(i, 2, n+1){
		a.push_back(a[i-1] * a[i-1] % m);
		memo.push_back(memo[i-1] + a[i]);
		if(st.count(a[i-1] * a[i-1] % m) != 0){
			nandakke = a[i-1] * a[i-1] % m;
			dokodatta = i;
			break;
		}
		st.insert(a[i-1] * a[i-1] % m);
	}
	if(nandakke == -1){
		cout << memo[n] << endl;
		return 0;
	}

	PREP(i, 1, n+1){
		if(a[i] == nandakke){
			len = dokodatta - i;
			ans = memo[i];
			ans += ((n-i)/len) * (memo[dokodatta] - memo[i]) + (memo[(n-i)%len+i] - memo[i]);
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}