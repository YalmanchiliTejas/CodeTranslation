#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v[8];
bool vis[8];
int ans,n,m,a,b;

void DFS(int len,int x){
	if(vis[x])return;
	if(len==n-1){
		ans++;
		return;
	}
	vis[x]=true;
	for(int i=0;i<v[x].size();i++){
		DFS(len+1,v[x][i]);
	}
	vis[x]=false;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)vis[i]=false;
	for(int i=0;i<m;i++){
		cin>>a>>b;a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans=0;
	DFS(0,0);
	cout<<ans<<endl;
	return 0;
}
