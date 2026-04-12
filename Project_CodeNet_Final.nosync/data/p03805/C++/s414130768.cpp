#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v,int n,bool visited[nmax]){
  bool all_visited = true;
  
  REP(i,n){
    if(visited[i]==false) all_visited=false;
  }
  
  if(all_visited) return 1;
  
  int ret=0;
  
  REP(i,n){
    if(graph[v][i]==false) continue;
    if(visited[i]) continue;
    
    visited[i]=true;
    ret+=dfs(i,n,visited);
    visited[i]=false;
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;

  cin >> n >> m;
  REP(i,m){
    int a,b;
    cin >> a >> b;
	graph[a-1][b-1] = graph[b-1][a-1] = true;
  }
  bool visited[nmax];
  REP(i,n) visited[i] = false;
  
  visited[0] = true;
  cout << dfs(0,n,visited) << endl;
}