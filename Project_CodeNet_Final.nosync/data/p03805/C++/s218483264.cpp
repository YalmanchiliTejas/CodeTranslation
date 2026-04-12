#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;

#define rep(i, a, b) for(ll (i) = (a); (i) < (b);++i)

int N, M;
const int MAX_N = 8;
const int MAX_M = 28;
bool graph[MAX_M][MAX_M];
bool visited[MAX_N] = {};

int dfs(int v){
  visited[0] = true;
  visited[v] = true;

  bool all_visited = true;
  rep(i, 0, N){
    if (visited[i] == false)
    {
      all_visited = false;
    }
  }

  if (all_visited)
  {
    // cout << "ret" << endl;
    return 1;
  }

  int cnt = 0;
  rep(i, 0, N){
    if (i != v && graph[v][i] && visited[i] == false)
    {
      // cout << v << " " << i << ", ";
      cnt += dfs(i);
      visited[i] = false;
    }
  }
  return cnt;
}

int main()
{
  cin >> N >> M;
  rep(i, 0, M){
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }
  cout << dfs(0) << endl;
  return 0;
}