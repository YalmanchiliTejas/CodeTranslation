#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> G(8, vector<int>(8, 0));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G.at(a).at(b) = G.at(b).at(a) = 1;
  }
  
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v.at(i) = i;
  }
  sort(v.begin(), v.end());
  
  int ans = 0;
  do {
    if(v.at(0) != 0){
      break;
    }
    
    bool judge = true;
    for (int i = 0; i+1 < n; i++) {
      int from = v.at(i);
      int to = v.at(i+1);
      if(G.at(from).at(to) != 1){
        judge = false;
      }
    }
    if(judge){
      ans++;
    }
  } while (next_permutation(v.begin(), v.end()));
    
  cout << ans << endl;

 
}
             
 
