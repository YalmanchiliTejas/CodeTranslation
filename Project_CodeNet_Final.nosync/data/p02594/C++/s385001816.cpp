#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#ifndef ONLINE_JUDGE
#include <custom/prettyprint.hpp>
#endif
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rb(i,x) for (auto& i : x)
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define UNIQUE(x) (x).resize(unique(all(x)) - begin(x))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define pow10(n) stoll("1"+string(n,'0'))
#define dbg(x) cout << ">>> " << #x << ": " << x << '\n'

const int MOD = 1e9+7; //998244353
const int inf = 1e9+3;
const ll INF = ll(3e18)+3;
const ld PI = acos((ld)-1);
const int dx[8] = {1,0,-1,0,1,1,-1,-1}, dy[8] = {0,1,0,-1,-1,1,1,-1};
mt19937_64 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll n) { return uniform_int_distribution<ll>(0, n)(rng); }
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void setIO(const string& s) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen((s+".in").c_str(),"r",stdin);
//	freopen((s+".out").c_str(),"w",stdout);
#endif
}

int main() {
    
    setIO("input");
    int x; cin >> x;
    cout << (x >= 30 ? "Yes\n" : "No\n");
    
}

/*  ! CHECK THIS IF YOU GET IT WRONG !
	* int overflow, array bounds, NO VLAs
	* uninitialized local variables, rounding errors
	* intermediate result type, scientific
	* special cases (n = 0 or 1?)
	* reset your variables in scope
	* INF not large enough for ans, adding value to _MAX
	* using wrong variables, sorting extra 0s in global array
	* comment out input from file
	* operator precedence
*/