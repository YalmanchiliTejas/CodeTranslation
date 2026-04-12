#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
using PP = pair<ll, P>;
#define rep(i,n) for(int i = 0; i < n; i++)
const int mx = 100005;
const int md = 1e9+7;
int n, m, s[2], u, v, w;
ll dis[2][mx], comb[2][mx], tm, ans, a2;
vector<P> node[mx];
priority_queue<PP, vector<PP>, greater<PP>> pq;
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d", s, s+1);s[0]--;s[1]--;
	rep(i,m){
		scanf("%d%d%d", &u, &v, &w);u--;v--;
		node[u].push_back(P{w,v});
		node[v].push_back(P{w,u});
	}
	rep(i,2){
		pq.push(PP{1, P{s[i],s[i]}}); comb[i][s[i]] = 1;
		while(!pq.empty()){
			PP tmp = pq.top(); pq.pop();
			int now = tmp.second.second;
			if(dis[i][now]){
				if(dis[i][now] == tmp.first) (comb[i][now] += comb[i][tmp.second.first]) %= md;
				continue;
			}
			dis[i][now] = tmp.first;
			comb[i][now] = comb[i][tmp.second.first];
			for(P it : node[now]) if(!dis[i][it.second]){
				pq.push(PP{tmp.first + it.first, P{now, it.second}});
			}
		}
	}
	rep(i,n) rep(j,2) (comb[j][i] *= comb[j][i]) %= md;
	rep(i,n){
		if(dis[0][i] + dis[1][i] == dis[0][s[1]]+1 && dis[0][i] == dis[1][i]){
			ans += comb[0][i]*comb[1][i]%md;
		}
		for(auto it: node[i]) if(it.second > i){
			ll w = it.first;
			rep(j,2){
				ll d[2] = {dis[j][i], dis[j^1][it.second]};
				if(d[0]+d[1]+w == dis[0][s[1]]+1 && d[0]<d[1]+w && d[1]<d[0]+w){
					(ans += comb[j][i]*comb[j^1][it.second]) %= md;
				}
			}
		}
	}
	printf("%lld\n", (comb[0][s[1]] - ans + md)%md);
}
