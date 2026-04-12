#include <bits/stdc++.h>
using namespace std;
#define int long long   // aaaaaaaaaaaaaaaaaa
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
template<typename T, typename U>ostream& operator << (ostream& os, pair<T, U>& pair_var)
{os << "(" << pair_var.first << ", " << pair_var.second << ")";return os;}
// head

int x,s,t,m,n,k,res;
int a[501000] = {};
int b[501000] = {};
int c[501000] = {};
vector<PII> g[500010];
queue<int> que2;
ll dp1[100010]={}, dp2[100010]={};
//string s;
vector<ll> dijkstra(ll n, vector<pair<ll,ll> >* G, ll s) {
    vector<ll> d(n, 1ll<<60); d[s] = 0;
    priority_queue<pair<ll, ll> > que;
    que.push(make_pair(0ll, s));
    while (!que.empty()) {
			auto p = que.top();que.pop();
			ll prov_cost = p.first;
			ll src = p.second;
			if(d[src]<prov_cost) continue;
			rep(i,0,g[src].size()){
				ll dest = g[src][i].first;
				ll weight = g[src][i].second;
				if ((d[dest] > d[src] + weight)){
					d[dest] = d[src] + weight;
					que.push({-d[dest],dest});
				}
			}
		}
    return d;
}

signed main() {
	std::cin >>n>>m>>s>>t;
	s--,t--;
	rep(i,0,m){
		std::cin >> a[i]>>b[i]>>c[i];
		b[i]--,a[i]--;
		g[a[i]].pb(mp(b[i], c[i]));
		g[b[i]].pb(mp(a[i], c[i]));
	}
	vector<ll> d = dijkstra(n, g, s);
	vector<PII> vec;
	rep(i,0, n) vec.pb({d[i], i});
	sort(all(vec));
	dp1[s] = 1;
	rep(i,0,n){
		for(auto e : g[vec[i].second]){
			if(d[vec[i].second] + e.second == d[e.first]) {
        dp1[e.first] += dp1[vec[i].second];
				dp1[e.first] %= mod;
      }
		}
	}
	d = dijkstra(n, g, t);


	vector<ll> d1 = dijkstra(n, g, s);
	dp2[t] = 1;
for(int i=n-1; i>=0; --i) {
	for(PII e: g[vec[i].second]) {
		if(d1[vec[i].second] == d1[e.first] + e.second) {
			dp2[e.first] += dp2[vec[i].second];
			dp2[e.first] %= mod;
		}
	}
}
	res = dp1[t]*dp2[s]%mod;
	rep(i,0,n){
		if( d[i]*2ll == d[s] && d1[i]*2ll == d1[t]){
			res -= ((dp1[i]%mod*dp1[i]%mod)*dp2[i]%mod)*dp2[i]%mod;
			res += mod;
			res %= mod;
		}
	}

	rep(i,0,m){
		if(d1[a[i]]*2ll <d[s] && d[b[i]]*2ll <d[s] && d[b[i]]+c[i] == d[a[i]] && d1[a[i]]+c[i] == d1[b[i]]){
			res -= ((dp1[a[i]]%mod*dp1[a[i]]%mod)*dp2[b[i]]%mod)*dp2[b[i]]%mod;
			res += mod;
			res %= mod;
		}
		else if (d[a[i]]*2ll < d[s] && d1[b[i]]*2ll < d[s] && d[a[i]]+c[i] == d[b[i]] && d1[b[i]]+c[i] == d1[a[i]]){
			res -= ((dp2[a[i]]%mod*dp2[a[i]]%mod)*dp1[b[i]]%mod)*dp1[b[i]]%mod;
			res += mod;
			res %= mod;
		}
	}
	res %= mod;
	std::cout << res << '\n';
}
