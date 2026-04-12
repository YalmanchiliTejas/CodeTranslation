#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int, int> P;
vector<int>v[10];
int n, m;
int ans;
void dfs(int now, int cnt, int graph[]);

int main() {
  cin >> n >> m;
  int graph[10] = {};
  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }
  graph[0] = 1;
  dfs(0, 1, graph);
  
  cout << ans << endl;
  
  return 0;
}

void dfs(int now, int cnt, int graph[]) {
  
  bool flag = true;
  for(int i = 0; i < v[now].size(); ++i) {
    if(graph[v[now][i]] == 0) {
      flag = false;
      graph[v[now][i]] = 1;
      dfs(v[now][i], cnt + 1, graph);
      graph[v[now][i]] = 0;
    }
  }
  if(flag && cnt == n) ++ans;

  return;
}
  
