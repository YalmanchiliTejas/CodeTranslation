#include <bits/stdc++.h>
using namespace std;

int g[10][10];
int ans;
int v[10];
int N,M;
void dfs(int start,int score){
	if(N==score)ans++;
	for(int i=0;i<N;i++){
		if(g[start][i] && !v[i]){
			v[i]=1;
			dfs(i,score+1);
			v[i]=0;
		}
	}
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a][b]=1;
		g[b][a]=1;
	}
	v[0] = 1;
	dfs(0,1);
	v[0] = 0;
	cout << ans << endl;
}