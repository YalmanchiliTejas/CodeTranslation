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

int N, M, S, T;
ll A[MAX_N], B[MAX_N], C[MAX_N];
vector<pl> G[MAX_N];

ll D[2][MAX_N], E[2][MAX_N];

void pre(int s, ll d[MAX_N], ll e[MAX_N]) {
	fill(d, d + N, linf);
	priority_queue<pl, vector<pl>, greater<pl>> que;
	que.push(pl(0, s));
	d[s] = 0;
	e[s] = 1;

	while(!que.empty()) {
		pl p = que.top(); que.pop();
		int v = p.sec; ll cost = p.fst;
		if(d[v] < cost) continue;

		rep(i, 0, sz(G[v])) {
			int n = G[v][i].fst; ll tc = G[v][i].sec;
			if(d[n] > cost + tc) {
				d[n] = cost + tc;
				e[n] = e[v];
				que.push(pl(d[n], n));
			}
			else if(d[n] == cost + tc) {
				ADD(e[n], e[v]);
			}
		}
	}
}


void solve() {
	cin >> N >> M;
	cin >> S >> T; S--; T--;
	rep(i, 0, M) {
		cin >> A[i] >> B[i] >> C[i];
		A[i]--; B[i]--;
		G[A[i]].pb(pl(B[i], C[i]));
		G[B[i]].pb(pl(A[i], C[i]));
	}
	pre(S, D[0], E[0]);
	pre(T, D[1], E[1]);
	// debug(vl(D[0], D[0] + N));
	// debug(vl(E[0], E[0] + N));
	// debug(vl(D[1], D[1] + N));
	// debug(vl(E[1], E[1] + N));
	//
	ll dist = D[0][T];
	ll ans = E[0][T] * E[0][T] % mod;

	// debug(ans, dist);
	rep(i, 0, M) {
		int a = A[i], b = B[i]; ll cost = C[i];
		if(D[0][a] > D[0][b]) swap(a, b);
		if(D[0][a] + cost + D[1][b] == dist) {
			if(D[0][a] * 2 < dist && D[0][b] * 2 > dist) {
				ADD(ans, mod - E[0][a] * E[1][b] % mod * E[0][a] % mod * E[1][b] % mod);
			}
		}
	}
	rep(i, 0, N) {
		if(D[0][i] * 2 == dist) {
			ADD(ans, mod - E[0][i] * E[1][i] % mod * E[0][i] % mod * E[1][i] % mod);
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

