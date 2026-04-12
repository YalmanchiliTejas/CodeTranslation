#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int ll;

int visited[8];
int G[8][8];
int ans;
int n,m;
void dfs(int s,int cnt){
	if(cnt==n){
		ans++;
		return;
	}
	visited[s]=1;
	for(int i=0;i<n;i++){
		if(G[s][i]&&!visited[i]){
			dfs(i,cnt+1);
		}
	}
	visited[s]=0;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y; cin >> x >> y;
		x--; y--;
		G[x][y]=G[y][x]=1;
	}
	ans=0;
	dfs(0,1);
	cout << ans << endl;
	return 0;
}