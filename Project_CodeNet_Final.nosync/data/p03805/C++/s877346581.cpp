#include<iostream>
using namespace std;

int n,m;
int link[9][9]={};

int dfs(int v,int d,int* visit){
	if(d==n-1) return 1;
	int vis[9];
	for(int i=0;i<9;i++) vis[i]=visit[i];
	vis[v]=1;
	int res=0;
	for(int i=1;i<=n;i++){
		if(visit[i]) continue;
		if(link[v][i]) res+=dfs(i,d+1,vis);
	}
	return res;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin >> a >> b;
		link[a][b]=1;
		link[b][a]=1;
	}
	int visit[9]={};
	cout << dfs(1,0,visit) << endl;

}
