#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 
  
#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int MOD = 998244353;
const int MX = (int)1e6 + 10;

void add_self(int &x, int y, int md = MOD){x += y; if(x >= md) x -= md;}
void sub_self(int &x, int y, int md = MOD){x -= y; if(x < 0) x += md;}
void mul_self(int &x, int y, int md = MOD){x = x * 1LL * y % md;}
inline int mul(int x, int y, int md = MOD){return x * 1LL * y % md;}
inline int add(int x, int y, int md = MOD){x += y; if(x >= md) x -= md; return x;}
inline int sub(int x, int y, int md = MOD){x -= y; if(x < 0) x += md; return x;}

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

vector<int> read(int n, int k){
	vector<int> vec(n);
	for(int i = 0; i < k; ++i) cin >> vec[i];
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for(int i = k; i < n; ++i)
		vec[i] = (a * 1ll * vec[i - 2] + b * 1ll * vec[i - 1] + c) % d;
	return vec;
}

inline int calc(int x, int m){
	return (x * 1ll * x) % m;
}

void solve(){
	ll n;
	int x, m;
	cin >> n >> x >> m;

	vector<int> seen(m, -1), val(m);
	vector<ll> pref(m);

	seen[x] = 0;
	val[0] = x;
	pref[0] = x;

	ll res = x;
	for(int i = 1; i < n; ++i){
		val[i] = calc(val[i - 1], m);
		pref[i] += val[i] + pref[i - 1];
		if(seen[val[i]] != -1){ // cycle detected
			ll rem = n - i; // including this move
			int fs_idx = seen[val[i]];
			int len = i - fs_idx;
			ll c_val = pref[i - 1] - (fs_idx == 0 ? 0 : pref[fs_idx - 1]);
			res += (rem / len) * c_val;
			// cout << pref[i - 1] << " " << pref[i] << '\n'; 
			// cout << i << " " << len << " " << res << " " << c_val << "\n";
			rem %= len;
			if(rem)
				res += pref[fs_idx + rem - 1] - (fs_idx == 0 ? 0 : pref[fs_idx - 1]);	
			break;
		}
		else{
			res += val[i];
			seen[val[i]] = i;
		}
	}

	cout << res << "\n";
	
	return;
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);

	int t;
	t = 1;
	// cin >> t;
	// pre();
	for(int i = 1; i <= t; ++i){
		// cout << "Case #" << i << ": ";
		solve();
		// cout << '\n';
		// cout << endl;
	}

	return 0;
}