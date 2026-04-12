#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
using ll = long long;
using P = pair<ll, int>;

const int mod = 1000000007;
struct mint {
  ll x; 
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

struct Edge{
	int to;
	ll cost;
	Edge(int t, ll c) : to(t), cost(c){}
};

using p_vec = pair<vector<ll>, vector<mint>>;

int n;
vector<vector<Edge>> g; 

p_vec dijkstra(int start){
	vector<ll> dist(n, LINF);
	vector<mint> cnt(n, 0); 
	priority_queue<P, vector<P>, greater<P>> que;
	cnt[start] = 1;
	dist[start] = 0;
	que.push({dist[start], start});

	while(!que.empty()){
		auto v = que.top();
		que.pop();
		int from = v.second;
		ll d = v.first;
		if(d > dist[from])continue;

		for(auto nv : g[from]){
			int to = nv.to;
			ll cost = nv.cost;
			if(dist[from] + cost < dist[to]){
				cnt[to] = cnt[from];
				dist[to] = dist[from] + cost;
				que.push({dist[to], to});
			}
			else if(dist[from] + cost == dist[to]){
				cnt[to] += cnt[from];
			}
		}
	}

	return {dist, cnt};
}

int main(){
  int m, s, t;
  cin >> n >> m >> s >> t;
  --s;
  --t;
  g.resize(n);
  for(int i = 0; i < m; ++i){
  	int u, v;
  	ll d;
  	cin >> u >> v >> d;
  	--u;
  	--v;
  	g[u].push_back(Edge(v, d));
  	g[v].push_back(Edge(u, d));
  }

  auto dij_s = dijkstra(s);
  auto dist_s = dij_s.first;
  auto cnt_s = dij_s.second;
  auto dij_t = dijkstra(t);
  auto dist_t = dij_t.first;
  auto cnt_t = dij_t.second;

  ll total_dist = dist_s[t];
  mint ans = cnt_s[t] * cnt_t[s];
  for(int i = 0; i < n; ++i){
  	if(dist_s[i] * 2 == dist_s[t]){
  		ans -= (cnt_s[i] * cnt_t[i]).pow(2);
  	}
  	for(auto nv : g[i]){
  		int from = i;
  		int to = nv.to;
  		ll cost = nv.cost;

  		if(dist_s[from] + cost + dist_t[to] != total_dist)continue;
  		if(dist_s[from] == dist_t[from] || dist_s[to] == dist_t[to])continue;
  		if(dist_s[from] < dist_t[from] && dist_s[to] > dist_t[to]){
  			ans -= (cnt_s[from] * cnt_t[to]).pow(2);
  		}
  	}
  }

  
  cout << ans.x << endl;

  return 0;
}
