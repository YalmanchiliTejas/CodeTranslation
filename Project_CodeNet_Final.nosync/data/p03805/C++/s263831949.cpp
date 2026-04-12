#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;


#define MAX_N 1005

int N,M;
vector<int> G[10];


inline void add_edge(int a,int b){
	G[a].push_back(b);
	G[b].push_back(a);
}

bitset<10> vis;
ll ans;

inline void dfs(int now){
	if(vis.count()==N){
		++ans;
		return;
	}

	for(int i=0;i<G[now].size();++i){
		if(!vis[G[now][i]]){
			vis[G[now][i]]=1;
			dfs(G[now][i]);
			vis[G[now][i]]=0;
		}
	}
}

int main(){
	cin>>N>>M;
	vis.reset();
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		add_edge(a,b);
	}
	/*if(M<N-1){
		puts("0");
		return 0;
	}*/

	vis[1]=1;
	dfs(1);

	printf("%lld\n",ans);

	return 0;
}