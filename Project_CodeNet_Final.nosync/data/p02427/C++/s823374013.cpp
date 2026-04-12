#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
 	ios::sync_with_stdio(false);
  int n;
  cin >> n;
  bitset<18> a[n];
  for(int i = 0; i < n; i++){
    a[i][i] = 1;
  }
  vector<vector<int>> v((1 << n));
  for(int x = 1; x < (1 << n); x++){
    bitset<18> b(x);
    bitset<18> e(0);
    for(int i = 0; i < 18; i++){
      if(b[i] == 0) continue;
      if(e == 0){
        e = a[i];
      }else{
        e |= a[i];
      }
    }
    int idx = e.to_ulong();
    for(int i = 0; i < 18; i++){
      if(b[i] == 1){
        v[idx].push_back(i);
      }
    }
  }
  for(int i = 0; i < v.size(); i++){
    cout << i << ":";
    for(int j = 0; j < v[i].size(); j++){
      cout << " " << v[i][j];
    }
    cout << "\n";
  }
  return 0;
}

