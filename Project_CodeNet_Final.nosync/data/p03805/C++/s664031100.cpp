#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

bool graph[8][8];

int dfs(int v,int n, bool visited[8]){

	bool all=true;
	for (int i = 0; i < n; i++){
		if(visited[i]==false)all=false;
	}

	if(all)return 1;

	int ret=0;
	for (int i = 0; i < n; i++){
		if(graph[v][i]==false)continue;
		if(visited[i])continue;

		visited[i]=true;
		ret+=dfs(i,n,visited);
		visited[i]=false;

	}

	return ret;

}


int main(){
	int n,m;
	cin>>n>>m;

	for (int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		graph[a-1][b-1]=true;
		graph[b-1][a-1]=true;
	}

	bool visited[8];
	memset(visited,false,sizeof(visited));

	visited[0]=true;

	cout<< dfs(0,n,visited) <<endl;

	return 0;
}