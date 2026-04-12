#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#define INF 2147483647
#define lli long long int

using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

vector< vector<bool> > graph(8,vector<bool>(8,false));

int dfs(vector<bool> visited,int v){
	bool all_visited = true;
	for (int i = 0; i < visited.size(); i++){
		if (!visited[i]){
			all_visited = false;
		}
	}

	if (all_visited){
		return 1;
	}
	
	int res = 0;
	for (int i = 0; i < visited.size(); i++){
		if (graph[v][i] == false) continue;
		if (visited[i] == true) continue;
		visited[i] = true;
		res += dfs(visited,i);
		visited[i] = false;
	}
	
	return res;

}


int main() {

	int n,m; cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
		graph[a-1][b-1] = graph[b-1][a-1] = true;
	}
	vector<bool> visited(n,false);
	visited[0] = true;
	cout << dfs(visited,0) << endl;
	return 0;
}



