#include <iostream>
#include <vector>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;

int n,m;
vector<bool>visited;
vector<vector<int> >g;
int num_visited = 0;
int ans = 0;

void dfs(int v){
    visited[v] = true;
    num_visited++;
    if(num_visited == n)    ans++;
    for(int i = 0; i < g[v].size(); i++){
	int next = g[v][i];
	if(!visited[next])  dfs(next);
    }
    visited[v] = false;
    num_visited--;
}

int main(){
    cin >> n >> m;
    g = vector<vector<int> >(n);
    visited = vector<bool>(n, false);
    rep(i, m){
	int a,b;    cin >> a >> b;
	a--;	
	b--;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
}
