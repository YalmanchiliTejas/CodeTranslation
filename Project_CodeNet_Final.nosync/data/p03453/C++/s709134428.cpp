#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mmp make_pair
#define oset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<vii> al;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
al g,h,rh;
vl d;
ll vs[100100],vt[100100];
const ll M = 1e9+7;
ll sv,tv;
ll dfa(int u) {
	if(u == sv) {return 1;}
	if(vs[u] != -1) return vs[u];
	ll res = 0;
	for(int i=0;i<rh[u].size();i++) {
		ll v = rh[u][i].first;
		res += dfa(v);
	}
	res %= M;
	return vs[u] = res;
}
ll dfb(int u) {
	if(u == tv) {return 1;}
	if(vt[u] != -1) return vt[u];
	ll res = 0;
	for(int i=0;i<h[u].size();i++) {
		ll v = h[u][i].first;
		res += dfb(v);
	}
	res %= M;
	return vt[u] = res;
}
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	int n,m;
	cin >> n >> m;
	int s,t;
	cin >> s >> t;
	s--;t--;
	sv = s;tv = t;
	memset(vs,-1,sizeof(vs));
	memset(vt,-1,sizeof(vt));
	g.assign(n,vii());
	d.assign(n,INFL);
	while(m--) {
		ll a,b,c;
		cin >> a >> b >> c;a--;b--;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	priority_queue<pl,vector<pl>,greater<pl>> pq;
	pq.push({0,s});
	d[s] = 0;
	while(!pq.empty()) {
		ll u = pq.top().second,dist = pq.top().first;pq.pop();
		if(dist > d[u]) continue;
		for(int i=0;i<g[u].size();i++) {
			ll v = g[u][i].first;
			ll nd = dist+g[u][i].second;
			if(nd >= d[v]) continue;
			pq.push({nd,v});
			d[v] = nd;
		}
	}
	ll val = d[t];
	h.assign(n,vii());
	rh.assign(n,vii());
	bitset<100100> bs;
	for(int i=0;i<n;i++) {
		for(int j=0;j<g[i].size();j++) {
			int v = g[i][j].first;
			ll ev = g[i][j].second;
			if(d[v] == d[i]+ev) {
				h[i].push_back({v,ev});
				rh[v].push_back({i,ev});
			}
		}
	}
	ll tot = dfa(t);
	dfb(s);
	tot *= tot;
	tot %= M;
	for(int i=0;i<n;i++) {
		if(d[i]*2 == val) {
			ll ra = (dfa(i)*dfb(i))%M;
			tot -= ra*ra;
			tot = tot%M+M;
		}
		if(d[i]*2 < val) {
			for(int j=0;j<h[i].size();j++) {
				int v = h[i][j].first;
				if(d[v]*2 > val) {
					//cout << "choke " << i << " -> " << v << '\n';
					ll ra = (dfa(i)*dfb(v))%M;
					//cout << "funk " << ra << " ^2 " << '\n';
					tot -= ra*ra;
					tot = tot%M+M;
				}
			}
		}
	}
	tot = ((tot%M)+M)%M;
	cout << tot << '\n';
}