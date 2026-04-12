#include <iostream>
using namespace std;

int path[9][9];
int ind[9];
int vis[9];
int ans,n,m;

void DFS(int num,int ind){
	if(num==n){
		ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(path[ind][i]&&!vis[i]){
			vis[i] = 1;
			DFS(num+1,i);
			vis[i] = 0;
		}
	}
}

int main(){
	int a,b;
	
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		path[a][b] = 1;
		path[b][a] = 1;
	}
	ans = 0;
	vis[1] = 1;
	DFS(1,1);
	cout << ans;
}