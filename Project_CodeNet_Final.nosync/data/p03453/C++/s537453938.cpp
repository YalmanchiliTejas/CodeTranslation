#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
const lli inf=1e16,mod=1e9+7;

struct edge{
	int t,c,rev;
	lli w;
	edge() {}
	edge(int t,lli w)
	:t(t),c(0),rev(-1),w(w) {}
};

int n,m,s,t;
vector<edge> adj[100001];
lli dist[100001];
int vis[100001];

void dijk(int s,int t) {
	fill(dist,dist+n+1,inf);
	priority_queue<pli,vector<pli>,greater<pli>> que;
	que.push(pli(0,s));
	dist[s]=0;
	while(!que.empty()) {
		lli cost=que.top().first;
		int cur=que.top().second;
		que.pop();
		if(vis[cur]) continue;
		vis[cur]=1;
		for(auto &it:adj[cur]) {
			if(!vis[it.t] && dist[it.t] > cost+it.w) {
				dist[it.t]=cost+it.w;
				que.push(pli(dist[it.t],it.t));
			}
		}
	}
}

lli sc[100001],tc[100001];
int color[100001];
void getsc() {
	fill(vis,vis+n+1,0);
	priority_queue<pli,vector<pli>,greater<pli>> que;
	que.push(pli(0,s));
	vis[s]=1;
	sc[s]=1;
	
	while(!que.empty()) {
		lli cost=que.top().first;
		int cur=que.top().second;
		que.pop();
		color[cur]++;
		for(auto &it:adj[cur]) {
			if(dist[it.t]==cost+it.w) {
				it.c++;
				adj[it.t][it.rev].c++;
				sc[it.t]=(sc[it.t]+sc[cur])%mod;
				if(!vis[it.t]) {
					vis[it.t]=1;
					que.push(pli(cost+it.w,it.t));
				}
			}
		}
	}
}
void gettc() {
	fill(vis,vis+n+1,0);
	priority_queue<pli> que;
	que.push(pli(dist[t],t));
	tc[t]=1;
	vis[t]=1;
	
	while(!que.empty()) {
		lli cost=que.top().first;
		int cur=que.top().second;
		que.pop();
		color[cur]++;
		
		for(auto &it:adj[cur]) {
			if(dist[it.t]==cost-it.w) {
				it.c++;
				adj[it.t][it.rev].c++;
				tc[it.t]=(tc[it.t]+tc[cur])%mod;
				if(!vis[it.t]) {
					vis[it.t]=1;
					que.push(pli(cost-it.w,it.t));
				}
			}
		}
	}
}
lli find() {
	lli res=0;
	for(int i=1;i<=n;i++) {
		if(color[i]==2 && dist[i] <= dist[t]/2) {
			if(dist[t]%2==0 && dist[i]==dist[t]/2) {
				res = (res + sc[i]*tc[i]%mod*sc[i]%mod*tc[i]%mod)%mod;
			}
			else {
				for(auto &it:adj[i]) {
					if(color[it.t]==2 && it.c && dist[it.t] >= dist[t]/2+1) {
						res = (res + sc[i]*tc[it.t]%mod*sc[i]%mod*tc[it.t]%mod)%mod;
					}
				}
			}
		}
	}
	return res;
}

int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	for(int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back(edge(b,c));
		adj[b].push_back(edge(a,c));
		adj[a].back().rev=adj[b].size()-1;
		adj[b].back().rev=adj[a].size()-1;
	}

	dijk(s,t);
	getsc();
	gettc();
	
	lli ans=sc[t]*sc[t]%mod;
	ans = (ans-find())%mod;
	ans= (ans+mod)%mod;
	printf("%lld\n",ans);
	
	return 0;
}
