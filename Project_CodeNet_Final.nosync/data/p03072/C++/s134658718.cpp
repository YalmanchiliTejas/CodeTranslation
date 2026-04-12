#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int ans = 1;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h.at(i);
  }
  for(int i = 1; i < n; i++){
    bool ok = true;
    for(int j = 0; j < i; j++){
      if(h.at(i) < h.at(j)) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
}
      
   