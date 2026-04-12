#include <bits/stdc++.h>
using namespace std;

int ans=0;
int N;

void dfs(vector<vector<bool>> &graph,vector<bool> &visited,int V){
	for(int i=0;i<N;i++){
		if(visited.at(i))	continue;
		if(graph.at(V).at(i)==false)	continue;
		visited.at(i)=true;
		dfs(graph,visited,i);
		visited.at(i)=false;
	}

	bool flag=true;
	for(int i=0;i<N;i++)	if(visited.at(i)==false)	flag=false;
	if(flag)	ans++;
}

int main(){
	int M;
	cin >> N >> M;
	vector<vector<bool>> graph(N,vector<bool>(N,false));
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		graph.at(a).at(b)=true;
		graph.at(b).at(a)=true;
	}

	vector<bool> visited(N,false);
	visited.at(0)=true;
	dfs(graph,visited,0);
	cout << ans << endl;

	return 0;
}
