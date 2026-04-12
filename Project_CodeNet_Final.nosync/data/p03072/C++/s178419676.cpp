#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> m;
  m.push_back(0);
  int tmp_max = m[0];
  int ans = 0;
  for(int i = 0; i < n; i++){
    int tmp; cin >> tmp;
    m.push_back(tmp);
    if(tmp_max <= m.back()){
      ans += 1;
      tmp_max = m.back();
    }
  }
  cout << ans <<endl;
}