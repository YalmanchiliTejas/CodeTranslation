#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(),(x).rend()

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;

bool graph[8][8];
bool visited[8];

int dfs(int v,int n,bool visited[8]){
	bool all_visited=true;
	for (int i = 0; i < n; ++i){
		if(visited[i]==false)all_visited=false;
	}
	if(all_visited)return 1;

	int sum=0;

	for (int i = 0; i < n; ++i){
		if(graph[v][i]==false||visited[i]==true)continue;
		
		visited[i]=true;
		sum+=dfs(i,n,visited);
		visited[i]=false;
	}

	return sum;

}

int main(){
	int n,m;
	cin>>n>>m;

	int a,b;
	for (int i = 0; i < m; ++i){
		cin>>a>>b;
		graph[a-1][b-1]=graph[b-1][a-1]=true;
	}

	visited[0]=true;
	cout<<dfs(0,n,visited)<<endl;
	return 0;

}