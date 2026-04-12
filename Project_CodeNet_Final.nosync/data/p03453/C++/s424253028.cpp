#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
ll const mod = 1e9+7;
 
#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<vector<P>> edges(100010),edges1(100010),edges2(100010);
 
void dijkstra(int s,vector<ll>& dist) {
	priority_queue<P,vector<P>,greater<P>> que;
	dist[s] = 0;
	que.push(P(0,s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v =  p.second;
		if (dist[v] < p.first) continue;
		for (int i = 0;i < edges[v].size();++i) {
			P e = edges[v][i];
			if (dist[e.first] > dist[v]+e.second) {
				dist[e.first] = dist[v]+e.second;
				que.push(P(dist[e.first],e.first));
			}
		}
	}
}

void fukugen(int s,vector<ll>& dist) {
	vector<bool> used(100010,false);
	stack<int> st;
	st.push(s);
	used[s] = true;
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		for (P& e : edges[i]) if (dist[i] == dist[e.first]+e.second) {
			if (!used[e.first]) {
				used[e.first] = true;
				st.push(e.first);
			}
			edges1[i].push_back(e);
			edges2[e.first].push_back(P(i,e.second));
		}
	}
}

void dp(int s,vector<ll>& dist,vector<vector<P>>& edges,vector<ll>& dp) {
	priority_queue<P,vector<P>,greater<P>> que;
	vector<bool> used((int)dist.size(),false);
	dp[s] = 1;
	que.push(P(0,s));
	used[s] = true;
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		for (P& e : edges[p.second]) {
			(dp[e.first] += dp[p.second]) %= mod;
			if (!used[e.first]) {
				que.push(P(dist[e.first],e.first));
				used[e.first] = true;
			}
		}
	}
}

int main() {
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	s--;t--;
	vector<ll> dist1(n,1LL<<60),dist2(n,1LL<<60);
	vector<ll> dp1(n,0),dp2(n,0);
	for (int i = 0;i < m;++i) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;v--;
		edges[u].push_back(P(v,w));
		edges[v].push_back(P(u,w));
	}
	dijkstra(s,dist1);
	dijkstra(t,dist2);
	fukugen(s,dist2);
	dp(s,dist1,edges1,dp1);
	dp(t,dist2,edges2,dp2);
	ll ans = 0;
	ans = dp1[t]*dp2[s]%mod;
	for (int i = 0;i < n;++i) if (dist1[i]*2 == dist1[t] && dist2[i]*2 == dist1[t]) (ans -= dp1[i]*dp1[i]%mod*dp2[i]%mod*dp2[i]%mod) %= mod;
	for (int i = 0;i < n;++i) for (P& e : edges1[i]) if (dist1[i]*2 < dist1[t] && dist1[e.first]*2 > dist1[t]) (ans -= dp1[i]*dp1[i]%mod*dp2[e.first]%mod*dp2[e.first]%mod) %= mod;
	cout << (ans+mod)%mod << endl;
	return 0;
}