#include <bits/stdc++.h>
using namespace std;
  
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> con(8, vector<bool>(8, false));
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b; a--; b--;
    con.at(a).at(b) = con.at(b).at(a) = true;
  }
  bool checked[8];
  
  function<int(int, int)> dfs = [&](int cur, int visited){
    if (visited == n) return 1;
    int ret = 0;
    for (int i = 1; i < n; i++){
      if (con.at(cur).at(i) && (!checked[i])){
        visited++; checked[i] = true;
        ret += dfs(i, visited);
        visited--; checked[i] = false;
      }
    }
    return ret;
  };
  checked[0] = true;
  cout << dfs(0, 1) << endl;
}