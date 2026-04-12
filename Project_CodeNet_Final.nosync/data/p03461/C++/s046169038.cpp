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
void Debug() {cerr << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cerr<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 500010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = (1 << 30) - 1;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
mt19937 rng; //use it by rng() % mod, shuffle(all(vec), rng)
///////////////////////////////////////////////////////////////////////////////////////////////////

int N;
int A, B;
int D[20][20];
int E[MAX_N], F[MAX_N], C[MAX_N];
map<pi, int> M;

void add_edge(int a, int b, int c) {
	E[N] = a; F[N] = b; C[N] = c;
	N++;
}

void solve() {
	cin >> A >> B;
	rep(i, 0, A) {
		rep(j, 0, B) {
			cin >> D[i][j];
		}
	}
	rep(x, 1, A + 1) {
		rep(y, 1, B + 1) {
			bool found = false;
			rep(a, 0, 100 + 1) {
				rep(b, 0, 100 + 1) {
					int c = D[x - 1][y - 1] - (a * x + b * y);
					if(c < 0 || c > 100 || found) continue;
					bool ok = true;
					rep(i, 1, A + 1) {
						rep(j, 1, B + 1) {
							if(D[i - 1][j - 1] > a * i + b * j + c) {
								ok = false;
							}
						}
					}
					if(ok) {
						found = true;
						M[pi(a, 201 - b)] = c;
					}
				}
			}
			if(!found) {
				cout << "Impossible" << "\n"; return;
			}
		}
	}
	for(auto p: M) {
		add_edge(p.fst.fst, p.fst.sec, p.sec);
	}
	rep(i, 0, 100) {
		add_edge(i, i + 1, 101);
		add_edge(101 + i, 102 + i, 102);
	}
	cout << "Possible\n";
	cout << 202 << " " << N << "\n";
	rep(i, 0, N) {
		if(C[i] == 101) cout << E[i] + 1 << " " << F[i] + 1 << " " << "X\n";
		else if(C[i] == 102) cout << E[i] + 1 << " " << F[i] + 1 << " " << "Y\n";
		else cout << E[i] + 1 << " " << F[i] + 1 << " " << C[i] << "\n";
	}
	cout << 1 << " " << 202 << "\n";
}

uint32_t rd() {
	uint32_t res;
#ifdef __MINGW32__
	asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
	res = std::random_device()();
#endif
	return res;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
    cerr << fixed;
	cerr.precision(6);
	rng.seed(rd());
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
	if(!freopen("in.txt", "rt", stdin)) return 1;
#endif	
	solve();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}

