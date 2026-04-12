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
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int N, A, B, C, D;
ll dp[1050][1050];


ll fac[MAX_N], inv[MAX_N], fiv[MAX_N]; //fiv:inv(fac(i))

ll mod_pow(ll a, ll n) {
	if(n == 0) return 1;
	ll res = mod_pow(a, n / 2);
	if(n % 2 == 0) return res * res % mod;
	else return a * res % mod * res % mod;
}

ll invf(ll a) {
	return mod_pow(a, mod - 2);
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

ll C_(int a, int b) { //assume a >= b
	if(a < b || a < 0 || b < 0) return 0;
	return fac[a] * fiv[b] % mod * fiv[a - b] % mod;
}

void solve() {
	cin >> N >> A >> B >> C >> D;
	C_init(N + 50);

	dp[A][N] = 1;

	for(int i = A; i <= B; i++) {
		rep(n, 0, N + 1) {
			if(!dp[i][n]) continue;
			for(int j = C; j <= D; j++) {
				if(n - i * j >= 0) {
					// debug(i, n, j,n - i * j );
					ADD(dp[i + 1][n - i * j], 
							dp[i][n] * C_(n, i * j) % mod * fac[i * j] % mod * invf(mod_pow(fac[i], j)) % mod * fiv[j] % mod);
				}
				else break;
			}
			ADD(dp[i + 1][n], dp[i][n]);
		}
		// debug(i, vl(dp[i], dp[i] + N + 1));
	}
	cout << dp[B + 1][0] << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

