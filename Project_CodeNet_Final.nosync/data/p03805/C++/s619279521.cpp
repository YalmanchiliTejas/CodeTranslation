#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &g, vector<bool> &used, int v = 0, int depth = 0){
  int n = g.size();
  bool all_use = true;
  used[v] = true;
  for (int i = 0; i < n; i++) all_use &= used[i]; 
  if(all_use){
    used[v] = false;
    return 1; 
  }
  int res = 0;
  for (int i = 0; i < g[v].size(); i++) {
    if(used[g[v][i]])continue;
    res += solve(g, used, g[v][i], depth + 1);
  }
  used[v] = false;
  return res;
}

int main(){
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> used(n, false);
  std::cout << solve(g, used) << std::endl;
  return 0;
}
