#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100*1000+10,mod=1e9+7;
const ll INF = 1e18;
int n,m,s,t;
vector<pi>V[nax];
ll dist[nax][2];
int cnt[nax][2],ans;
ll path_len;

void Dijkstra(int start,bool typ) {
	for(int i = 1; i <= n; ++i) {
		dist[i][typ] = INF;
	}
	dist[start][typ] = 0;
	cnt[start][typ] = 1;
	priority_queue< pair<ll,int> > PQ;
	PQ.push({0,start});
	while(!PQ.empty()) {
		int v = PQ.top().ND;
		ll d = -PQ.top().ST;
		PQ.pop();
		if(d > dist[v][typ]) {
			continue;
		}
		for(auto nbh : V[v]) {
			if(d + nbh.ND < dist[nbh.ST][typ]) {
				dist[nbh.ST][typ] = d + nbh.ND;
				cnt[nbh.ST][typ] = cnt[v][typ];
				PQ.push({-dist[nbh.ST][typ],nbh.ST});
			} else if(d + nbh.ND == dist[nbh.ST][typ]) {
				cnt[nbh.ST][typ] = (cnt[nbh.ST][typ] + cnt[v][typ])%mod;
			}
		}
	}
}

int main() {_
	cin >> n >> m >> s >> t;
	for(int a,b,c,i=1; i <= m; ++i) {
		cin >> a >> b >> c;
		V[a].emplace_back(b,c);
		V[b].emplace_back(a,c);
	}
	Dijkstra(s,0);
	Dijkstra(t,1);
	path_len = dist[t][0];
	for(int i = 1; i <= n; ++i) {
		if(dist[i][0] * 2 == path_len) {
			//I'm a middle vertex
			int diff_path = ((ll)cnt[i][0] * cnt[i][1])%mod;
			ans = (ans + ((ll)diff_path * diff_path))%mod;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(auto nbh : V[i]) {
			if(dist[i][0] + nbh.ND + dist[nbh.ST][1] == path_len) {
				if(dist[i][0] * 2 < path_len && dist[nbh.ST][0] * 2 > path_len) {
					//I'm a middle edge
					int diff_path = ((ll)cnt[i][0] * cnt[nbh.ST][1])%mod;
					ans = (ans + ((ll)diff_path * diff_path))%mod;
				}
			}
		}
	}
	int cnt_all = ((ll)cnt[t][0]*cnt[t][0])%mod;
	ans = (cnt_all - ans)%mod;
	if(ans<0) ans += mod;
	cout << ans;
	
}
