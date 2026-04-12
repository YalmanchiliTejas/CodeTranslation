#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;

const int nmax = 8;
bool graph[nmax][nmax];
int n, m;

int dfs(int v, vector<bool> visited) {
  bool pass = true;
  rep(i, n) if (visited[i] == false) pass = false;
  if (pass) return 1;

  int ret = 0;
  rep(i, n){
    if (graph[v][i] == false) continue;
    if (visited[i] == true) continue;
    visited[i] = true;
    ret += dfs(i, visited);
    visited[i] = false;
  }
  return ret;
}

int main(){
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  vector<bool> visited(nmax);
  rep(i, nmax) visited[i] = false;
  visited[0] = true;
  cout << dfs(0, visited) << endl;
}