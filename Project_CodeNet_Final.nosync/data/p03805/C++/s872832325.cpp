#include <bits/stdc++.h>
using namespace std;
	vector<vector<int>>g;
	vector<bool> visited;
	int n,m;

void add_edge(int a,int b){
	g[a].push_back(b);
	g[b].push_back(a);
}

int dfs(int i,int dpt){
//    cout<<dpt<<" "<<i+1<<endl;
	int ret=0;
	if(dpt==n)return 1;
	for(auto&& w:g[i]){
    if(!visited[w]){
      visited[i]=true;
      ret+=dfs(w,dpt+1);
      visited[i]=false;
	}
    }
  	return ret;
}


int main(){
	cin>>n>>m;
	g.resize(n);
	visited.assign(n,false);
	for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	add_edge(--a,--b);	
	}
	cout<<dfs(0,1)<<endl;
}