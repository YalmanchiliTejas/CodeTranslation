#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]) {
  bool all_visited = true;
  rep(i,N) if(!visited[i]) all_visited = false;
  if(all_visited) return 1;
  int ret = 0;
  rep(i,N) {
    if(!graph[v][i]) continue;
    if(visited[i]) continue;
    visited[i] = true;
    ret += dfs(i,N,visited);
    visited[i] = false;
  }
  return ret;
}

int main() {
  int N,M;
  cin >> N >> M;
  for(int i=0;i<M;++i){
    int A,B;
    cin >> A >> B;
    graph[A-1][B-1]=graph[B-1][A-1]=true;
  }
  bool visited[nmax];
  for(int i=0;i<N;++i){
  visited[i]=false;
  }
  visited[0]=true;
  cout << dfs(0,N,visited) << endl;
  return 0;
}