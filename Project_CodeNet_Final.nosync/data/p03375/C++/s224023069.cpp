#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int N; ll mod;
ll fac[MAX_N], inv[MAX_N], fiv[MAX_N]; //fiv:inv(fac(i))

ll mod_pow(ll a, ll n, ll mod) {
	if(n == 0) return 1;
	ll res = mod_pow(a, n / 2, mod);
	if(n % 2 == 0) return res * res % mod;
	else return a * res % mod * res % mod;
}

ll invf(ll a) {
	return mod_pow(a, mod - 2, mod);
}

void C_init(int n) {
	fac[0] = fac[1] = 1; inv[1] = 1;
	fiv[0] = fiv[1] = 1;
	rep(i, 2, n + 1) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		fiv[i] = fiv[i - 1] * inv[i] % mod;
	}
}

ll C(int a, int b) { //assume a >= b
	if(a < b || a < 0 || b < 0) return 0;
	return fac[a] * fiv[b] % mod * fiv[a - b] % mod;
}

ll dp[3010][3010];

void solve() {
	cin >> N >> mod;
	C_init(N + 10);

	dp[0][0] = 1;
	rep(i, 0, N) {
		rep(j, 0, N) {
			if(dp[i][j] == 0) continue;
			ADD(dp[i + 1][j + 1], dp[i][j]);
			ADD(dp[i + 1][j], dp[i][j] * (j + 1) % mod);
		}
	}
	// rep(i, 0, N + 1) {
	// 	rep(j, 0, N + 1) {
	// 		debug(i, j, dp[i][j]);
	// 	}
	// }
	ll ans = 0;
	rep(i, 0, N + 1) {
		ll dps = 0;
		ll pown = mod_pow(2, mod_pow(2, N - i, mod - 1), mod);
		ll pp = mod_pow(2, N - i, mod);
		ll d = 1;
		rep(j, 0, i + 1) {
			ll pows = pown * d % mod;
			MUL(d, pp);
			ADD(dps, dp[i][j] * pows % mod);
		}
		if(i % 2 == 0) {
			ADD(ans, (C(N, i) * dps % mod));
		}
		else {
			ADD(ans, mod - (C(N, i) * dps % mod));
		}
	}
	cout << ans << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

