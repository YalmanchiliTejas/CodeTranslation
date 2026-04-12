#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int n,m;
vector<vector<bool>> g(8,vector<bool>(8));
int ans=0;

void dfs(int a,vector<bool> c){
	c[a]=true;
	bool flg=true;
	rep(i,n) if(!c[i]) flg=false;
	if(flg) ans++;
	rep(i,n) if(g[a][i] && !c[i]) dfs(i,c);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i,m){
		int x,y;
		cin >> x >> y;
		g[--x][--y]=true;
		g[y][x]=true;
	}
	vector<bool> c(n);
	dfs(0,c);
	cout << ans << endl;
}