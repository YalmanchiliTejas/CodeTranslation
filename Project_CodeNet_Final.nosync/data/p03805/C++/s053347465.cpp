#include<bits/stdc++.h>
using namespace std;

int N,M,a,b,startingPoint,visite,ans;
vector<int> adj[100100];
bool visited[100100];

void dfs(int x){
	if(visited[x]) return;
	visited[x] = true;
    visite++;
	for(int i = 0;i < adj[x].size();i++){
		int y = adj[x][i];
		dfs(y);
	}
    if (visite == N) ans++;
	visited[x] = false;
    visite--;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i = 1;i <= M;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
    cout<<ans<<endl;
	return 0;
}