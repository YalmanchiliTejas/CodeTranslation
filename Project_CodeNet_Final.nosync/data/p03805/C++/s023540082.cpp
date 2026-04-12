#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

const int limit = 8;
vector<vbool> graph(limit,vbool(limit,false));
vbool visited(limit,false);

int dfs(int v,int n);

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--,b--;
    graph[a][b] = graph[b][a] = true;
  }
  cout << dfs(0,n) << endl;
}

int dfs(int v, int n){
  bool all_visited = true;
  ll ans = 0;
  visited[v] = true;
  //rep(i,limit) cout << visited[i];
  //cout << endl;
  //cout << "v" << v << endl;
  rep(i,n){
    if(!(visited[i])) all_visited = false;
  }
  if(all_visited){
    visited[v] = false;
    return 1;
  }
  rep(v2,n){
    //cout << v <<" "<< v2 << "  " << graph[v][v2] << endl; 
    if(graph[v][v2] == false) continue;
    if(visited[v2]) continue;
    ans += dfs(v2,n);
  }
  visited[v] = false;
  return ans;
}