//#pragma comment(linker, "/STACK:1024000000,1024000000")
/* vim: set fdm=marker */
//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int iinf = 0x7fffffff;
const ll linf = ~(1LL<<63);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll, int> mli;
typedef map<ll, ll> mll;
template<typename T>
inline T gcd(T a, T b) {
	if(a < 0) return gcd(-a, b);
	if(b < 0) return gcd( a,-b);
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll qpow(ll a, ll n, ll mod) {
	a %= mod;
	ll ans = 1LL;
	while(n) {
		if(n & 1) ans = (ans*a % mod);
		a = (a*a % mod);
		n >>= 1;
	}
	return ans;
}

inline ll rev(ll a, ll p) {
	return qpow(a, p - 2, p);
}

#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define rep(x, st, en) for(int x = st; x < en; x++)
#define rer(x, st, en) for(int x = st; x >= en; x--)
#define pb push_back
#define mp make_pair
#define dbgm(msg, var) cerr<<#msg<<" "<<#var<<" = "<<var<<endl; 
#define dbg(var) cerr<<#var<<" = "<<var<<endl;
#define X first
#define Y second
inline int in() { int x; cin>>x; return x; }
#ifdef ALNDBG
namespace alndbg {
	clock_t s, e;
}
#endif

inline void tic() {
#ifdef ALNDBG
	alndbg::s = clock();
#endif
}

inline void toc() {
#ifdef ALNDBG
	alndbg::e = clock();
	cerr<<1000.0 * (alndbg::e - alndbg::s) / CLOCKS_PER_SEC<<" ms"<<endl;
#endif
}

//}}}

// -------------------- Spliters ------------------------
const int maxn = 1010;
int dx[2] = { 0, 1};
int dy[2] = { 1, 0};
int H, W;
bool vis[maxn][maxn];
char m[maxn][maxn];
void go(int x, int y) {
	vis[x][y] = true;
	for(int i = 0; i < 2; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(0 <= nx && nx < H && 0 <= ny && ny < W && m[nx][ny] == '#') {
			go(nx, ny);
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin>>H>>W;
	rep(i, 0, H) cin>>m[i];
	if(m[0][0] != '#') { cout<<"Impossible"<<endl; return 0; }
	go(0, 0);
	if(!vis[H - 1][W - 1]) { cout<<"Impossible"<<endl; return 0; }
	bool ok = true;
	rep(i, 0, H) {rep(j, 0, W) if(m[i][j] == '#' &&!vis[i][j]) {
		ok = false;
		break;
	}
		if(!ok) break;
	}
	if(!ok) { cout<<"Impossible"<<endl; return 0;}
	cout<<"Possible"<<endl;
	return 0;
}
// --USE C++11
// *-USE O2
