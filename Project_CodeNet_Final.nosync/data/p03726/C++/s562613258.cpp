#include <bits/stdc++.h>

using namespace std;

vector< int > g[100000];

int dfs(int idx, int par)
{
  int ret = 0;
  for(auto to : g[idx]) {
    if(to == par) continue;
    ret += dfs(to, idx);
  }
  if(ret >= 2) {
    cout << "First" << endl;
    exit(0);
  }
  return (ret ^ 1);
}


int main()
{
  int N;
  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if(dfs(0, -1)) cout << "First" << endl;
  else cout << "Second" << endl;
}