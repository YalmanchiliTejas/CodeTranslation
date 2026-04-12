// Standard Stuff
#include <bits/stdc++.h>
using namespace std;

// Macros
#define F  first
#define S  second
#define PB push_back

// Rename Datatypes
using ll  = long long;
using ld  = long double;
using pii = pair<int,int>;

// Common Functions
ll fastpow(ll a, ll ex){ ll res = 1; while(ex){ if(ex & 1) res *= a; a *= a; ex >>= 1; } return res; }
ll fastpow(ll a, ll ex, ll m){ a %= m; ll res = 1; while(ex){ if(ex & 1) res = (a*res) % m; a = (a*a) % m; ex >>= 1; } return res; }
ll modinverse(ll a, ll m){ ll m0 = m, y = 0, x = 1; while (a > 1){ ll q = a / m; a %= m; swap(a,m); x -= q*y; swap(x,y); } if(x < 0) x += m0; return x; }

// HELPERS
//  Tedious Grid Movements
vector<pii> moves_grid = { {0,1} , {0,-1} , {1,0} , {-1,0} };
inline bool move_okay(int x, int y, int n, int m) { return 0 <= x and x < n and 0 <= y and y < m; }
//  Remember:
//   * vec.assign() GOOD; vec.resize() BAD
//   * comparator uses <

// Output, Common Containers
template <typename T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <typename T> ostream& operator << (ostream &os, const set<T> &v)    { for (T i : v) os << i << ' '; return os; }
template <typename T, typename S> ostream& operator << (ostream &os, const pair<T,S> &v) { os << "(" << v.F << "=>" << v.S << ") "; return os; }
template <typename T, typename S> ostream& operator << (ostream &os, const map<T,S> &v)  { for (auto i : v) os << i << ' '; return os; }

// Debugging
#ifdef SANYAM1101
	#define trace(args...) do{ cerr << "TRACE ON! (Line: " << __LINE__ << ")\n"; auto _stream = istringstream{string{#args}}; d_f(_stream, args); } while(0)
	void d_f(__attribute__((unused)) istringstream& _stream) {}
	template<typename Head, typename... Tails> void d_f(istringstream& _stream, Head H, Tails... T) { string _name; _stream >> _name; if(_name.back() == ',') _name.pop_back(); cerr << "\t" << _name << " <=> [" << H << "]\n"; d_f(_stream, T...); }
#else
	#define trace(args...)
#endif


// CODE STARTS HERE

void solve(){
	int num = 0;

	for(int i = 0; i < 3; ++i){
		int x; cin >> x;
		num = num * 10 + x;
	}

	cout << (num % 4 ? "NO\n" : "YES\n");
}

signed main (void){
	// Fast_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Set Fixed Notation (default sucks), High Precision for Floating-Point Output
	cout << fixed << setprecision(20);

	// Multiple TCs
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
}
