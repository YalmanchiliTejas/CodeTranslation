#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m,res;
vector < int > adj[10];
bool V[10];
void dfs(int ver,int cnt){
	if(cnt==n){
		res++;
		return;
	}
	int xb;
	for(xb=0;xb<adj[ver].size();xb++){
		if(!V[adj[ver][xb]]){
			V[adj[ver][xb]]=1;
			dfs(adj[ver][xb],cnt+1);
			V[adj[ver][xb]]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	int xb,x2,a,b;
	for(xb=0;xb<m;xb++){
		cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	V[0]=1;
	dfs(0,1);
	cout<<res;
	return 0;
}