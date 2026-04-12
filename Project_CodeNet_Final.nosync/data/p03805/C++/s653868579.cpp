#include <bits/stdc++.h>
//#define int long long
using namespace std;
using graph=vector<vector<int>>;

vector<bool> visited;
int ans=0;
int num=0;
int N,M;
graph G;
void dfs(int v){
	visited[v]=true;
	num++;
	if(num==N){
		ans++;
	}else{
		for(auto nv : G[v]){
			if(visited[nv])continue;
			else dfs(nv);
		}
	}
	num--;
	visited[v]=false;
}

signed main(){
	cin>>N>>M;
	G.assign(N,vector<int>(0));
	for(int i=0;i<M;i++){
		int a,b; cin>>a>>b; a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	visited.assign(N,false);
	dfs(0);
	cout<<ans<<endl;
	return 0;
}

