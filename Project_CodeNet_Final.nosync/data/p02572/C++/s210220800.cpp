// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int NINF = -1*INF;
const long long LLINF = 1ll << 60;
const long long LLNINF = -1*LLINF;

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
	return os << "[ " << p.first << ", " << p.second << "]" ;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef vector<vld> vvld;
 
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define revAll(x) x.rbegin(), x.rend()
#define gcd(a, b) __gcd(a, b)
#define popcount(x) __builtin_popcount(x)
#define isize(x) (int)(x.size())
#define rep(i,n) for(int i = 0; i < n; i++)
#define exists(x,m) m.find(x) != m.end()
#define umap unordered_map
#define uset unordered_set
#define pq priority_queue

const ll MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	vi A = vi();
	rep(i, n) {
		int x; cin >> x;
		A.pb(x);
	}
	ll ans = 0;
	vll psums = {A[0]};
	for (int i = 1; i < n; i++) {
		psums.pb(psums[i-1] + A[i]);
		psums[i] %= MOD;
	}
	for (int i = 1; i < n; i++) {
		ll x = (psums[i-1] * A[i]) % MOD;
		ans += x;
		ans %= MOD;
	}
	cout << ans;
}