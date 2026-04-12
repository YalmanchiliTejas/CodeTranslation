#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
// #pragma GCC optimize("O2")
typedef long long int ll;
typedef long double ld;
typedef map <ll,ll> mm;
typedef vector <ll> mv;
typedef pair <ll,ll> mp;
typedef set <ll> ms;
typedef multiset <ll> mms;
typedef queue <ll> mq;
typedef deque <ll> mdq;
typedef stack <ll> mst;
typedef priority_queue <ll> mpq;
typedef priority_queue <ll, vector<ll>, greater<ll> > mmh;
typedef complex<double> cd;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define flush cout.flush();
#define all(v) v.begin(),v.end()
#define deb(x) cout << #x << " " << x << endl;
#define ff first
#define ss second
#define pb(v) push_back(v)
#define lb(v) lower_bound(v)
#define ub(v) upper_bound(v)
#define cn continue
#define forl(i,n) for(ll i=0;i<n;i++)
#define forlr(i,n) for(ll i=n-1;i>=0;i--)
#define rev(s) reverse(s.begin(),s.end())
void swap(ll &a,ll &b) {
	ll tmp=a;
	a=b;
	b=tmp;
}
ll atoistring(string s) {
	stringstream lol(s);
	ll x;
	lol>>x;
	return x;
}
void pv(mv v) {
	forl(i,v.size()) cout<<v[i]<<" ";
	cout<<"\n";
}
void pa(ll *v, ll size) {
	forl(i,size) cout<<v[i]<<" ";
	cout<<"\n";
}
void removeDups(mv &v) {
	sort(all(v));
	mv::iterator it = unique(v.begin(), v.end());
	v.resize(distance(v.begin(), it));
}
inline ld kthRoot(ld n, ll k) {
	return pow(k, (1.0 / k) * (log(n) / log(k)));
}
ll power(ll x, ll y, ll p) {
	ll res=1;
	x=x%p;
	while(y>0) {
		if(y&1) res = (res*x)%p;
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
void checkmod(ll &x, ll mod) {
	if(x>=mod) x%=mod;
}

ll mod = 1e9 + 7;

ll arr[200005];
void thisIsMain() {
	ll n;
	cin>>n;
	forl(i,n) cin>>arr[i];
	ll s = 0;
	forl(i,n) {
		s += arr[i];
		if(s >= mod) checkmod(s, mod);
	}
	ll ans = (s * s) % mod;
	forl(i,n) {
		ans -= (arr[i] * arr[i]) % mod;
		if(ans < 0) ans += mod;
	}
	ans *= power(2, mod - 2, mod);
	ans %= mod;
	cout<<ans<<"\n";
}

int main(void)
{
	fastio
	ll t = 1;
	// cin>>t;
	while(t--) thisIsMain();
	return 0;
}