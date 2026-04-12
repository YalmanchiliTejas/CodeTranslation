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
  vector<int> path(n - 1);
  for (int i = 1; i < n; i++){
    path.at(i - 1) = i;
  }
  
  int ans = 0;
  do{
    bool ok = true;
    int p = 0;
    for (int i = 0; i < n - 1; i++){
      if (!con.at(p).at(path.at(i))) ok = false;
      p = path.at(i);
    }
    if (ok) ans++;
  }while(next_permutation(path.begin(), path.end()));
  cout << ans << endl;
}