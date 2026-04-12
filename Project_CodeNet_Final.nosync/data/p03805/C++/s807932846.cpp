#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)

const ll INF=1e9+7;
int n,m,ans;
bool f[9][9],visited[9];
void dfs(int p,int num){
	if(num==n){
		ans++;
		return;
	}
	visited[p]=1; 
	rep(i,n){
		if(!visited[i]&&f[p][i]){
			dfs(i,num+1);
		}
	}
	visited[p]=0;
	return;
}
int main()
{
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n>>m;
	rep(i,m){
		int x,y;
		cin>>x>>y;
		f[x][y]=f[y][x]=1;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}