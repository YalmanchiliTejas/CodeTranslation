#include <bits/stdc++.h>

using namespace std;

enum
{
  BLACK, WHITE
};

int N;
vector< int > g[100000];
int sub[100000];
int pa[100000];

int dfs(int idx, int par = -1)
{
  sub[idx]++;
  int visited = 0;
  for(auto &to : g[idx]) {
    if(par == to) continue;
    visited++;
  }
  if(visited == 0) return (BLACK);
  int bb = 0;
  for(auto &to : g[idx]) {
    if(par == to) continue;
    int get = dfs(to, idx);
    sub[idx] += sub[to];
    if(get == BLACK) ++bb;
  }
  if(bb >= 2) {
    cout << "First" << endl;
    exit(0);
  }

  if(sub[idx] % 2 == 0) return (WHITE);
  else return (BLACK);
}

int main()
{


  cin >> N;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  if(N == 2) {
    cout << "Second" << endl;
    return (0);
  }

  if(dfs(0) == BLACK) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }

}