#include<bits/extc++.h>
#ifdef _debug 
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#include<bits/stdc++.h>
#define dout(i) 0&&0
#endif
#pragma GCC optimize("unroll-loops,no-stack-protector,O3")
#define eout(i) {cout << (i) << '\n';exit(0);}
#define rout(i) {return cout << (i) << '\n', 0;}
#define priority_queue __gnu_pbds::priority_queue
#define unordered_map __gnu_pbds::gp_hash_table
#define rep(a, b) {for(int _i = a;_i > 0;--_i){b;}}
#define multe int _T;for(cin >> _T;_T--;)
using namespace std;
using ll = long long;using ull = unsigned long long;using ul = unsigned;using db = double;
using __gnu_pbds::null_type;
template<typename T> void read(int n, T s){while(n--)cin >> *s, ++s;}
template<typename T> void write(int n, T s){while(n--)cout << *s << " \n"[n==0], ++s;}
template<typename T> using rbtree = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T> inline ostream& operator << (ostream &ou, const vector<T> &a){for(auto it = a.begin();it != a.end();++it)ou << (it != a.begin() ? " " : "") << *it;return ou;}
template<typename T1, typename T2>inline istream& operator >> (istream &in, pair<T1, T2> &a){return in >> a.first >> a.second;}
template<typename T1, typename T2>inline ostream& operator << (ostream &ou, const pair<T1, T2> &b){return ou << b.first << ' ' << b.second;}
template<typename T> inline long long pow(long long v, long long t, const T &p){long long res = 1;for(;t;t >>= 1, v = v * v % p)if(t & 1)res = res * v % p;return res;}
ll n, k;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;	
	if(k == 0)eout(n * n);
	ll res = 0;
	for(int b = k+1;b <= n;++b){
		int o = res;
		for(int l = k, v = b;;v += b, l += b){
			if(v >= n){
				res += max(0ll, n-l+(n%b != 0));
				break;
			}
			else res += v-l;
		}
		// dout(b)<< res-o << '\n';
	}
	cout << res << '\n';
}