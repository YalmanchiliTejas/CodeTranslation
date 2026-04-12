#include <bits/stdc++.h>
#define Nmax 9
using namespace std;
bool graph[Nmax][Nmax];
bool visited[Nmax];
int dfs(int v,int N){
	bool all_visited = true;
	for(int i=1;i<=N;i++){
		if(visited[i]==false)all_visited=false;
	}
	if(all_visited)return 1;
	int ret = 0;
	for(int i=1;i<=N;i++){
		if(graph[v][i]==true && visited[i]==false){
			visited[i]=true;
			ret +=dfs(i,N);
			visited[i]=false;
		}
	}
	return ret;
}
int main(void){
	int N,M,ans;
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		int A,B;
		cin >> A >> B;
		graph[A][B]=graph[B][A]=true;
	}
	visited[1] = true;
	ans = dfs(1,N);
	cout << ans;
	return 0;
}