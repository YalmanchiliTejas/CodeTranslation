#include <bits/stdc++.h>
using namespace std;

int dfs(int n, vector<vector<bool>> con, int cur, bool *checked, int visited){
  if (visited == n) return 1;
  int ret = 0;
  for (int i = 0; i < n; i++){
    if (con.at(cur).at(i) && (!checked[i])){
      visited++; checked[i] = true;
      ret += dfs(n, con, i, checked, visited);
      visited--; checked[i] = false;
    }
  }
  return ret;
}
  
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> con(8, vector<bool>(8, false));
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b; a--; b--;
    con.at(a).at(b) = con.at(b).at(a) = true;
  }
  bool checked[8]; checked[0] = true;
  cout << dfs(n, con, 0, checked, 1) << endl;
}