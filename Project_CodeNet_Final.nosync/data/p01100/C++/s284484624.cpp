#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct edge{
	int to,cap,rev;
	edge(){}
	edge(int tt,int cc,int rr){
		to=tt;
		cap=cc;
		rev=rr;
	}
};

int n,m;
vector<edge> G[105];
int cnt[101];


void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}

vector<int> vec;
bool used[101];

int dfs(int v,int t,int f){
	if(v==t)return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

void solve(){
	for(int i=0;i<n;i++){
		G[i].clear();
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		add_edge(u,v,1);
		cnt[u]++;
	}
	bool update=true;
	while(update){
		update=false;
		int p_min=0,p_max=0;
		for(int i=1;i<n;i++){
			if(cnt[p_min]>cnt[i]){
				p_min=i;
			}
			if(cnt[p_max]<cnt[i]){
				p_max=i;
			}
		}

		for(int i=0;i<n;i++){
			if(!update && cnt[p_min]+1<cnt[i]){
				memset(used,false,sizeof(used));
				int val=dfs(i,p_min,1);
				if(val==1){
					update=true;
					cnt[i]--;
					cnt[p_min]++;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(!update && cnt[i]+1<cnt[p_max]){
				memset(used,false,sizeof(used));
				int val=dfs(p_max,i,1);
				if(val==1){
					update=true;
					cnt[p_max]--;
					cnt[i]++;
				}
			}
		}
		if(!update){
			printf("%d %d\n",cnt[p_min],cnt[p_max]);
			return;
		}
	}
}

int main(void){
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		solve();
	}
	return 0;
} 
