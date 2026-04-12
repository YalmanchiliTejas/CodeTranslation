//#pragma comment(linker, "/stack:200000000") //  (UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")  // $ (UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fast_cin ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define pb push_back
#define all(con) (con).begin(), (con).end()
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;++i)
#define fre(i,a,b) for(int i=a;i<=b;i++)
#define rpe(i,a,b) for(i=a-1;i>=b;i--)
#define rp(i,n) rep(i,0,n)
#define fr(i,n) fre(i,1,n)
#define ff(i,a,b) for(int i=a;i<=b;i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<"  ";__f(comma+1, args...);}
#else
#define trace(...)
#endif

template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}

int modpow(int x, int n, int m) {
	x %= m;
	int res = 1;
	while(n > 0) {
		if(n & 1)
		res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

const long long inf = 2e18 ;
const int mod = 1e9+7 ;
// const int mod = 998244353 ;

const int N = 1e5 + 10 ;

void solve() {
	int n,m;
	cin>>n>>m;
	if(n==m) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

signed main() {
        fast_cin;
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
        #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    	#endif

	int tests=1;
	// cin>>tests;
	while(tests--) {
		solve();
	}

return 0 ;
}

