#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  
  int ans = n;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(h.at(i) < h.at(j)) {
        ans--;
        break;
      }
    }
  }
  //ans = min(change1, change2);
  cout << ans << endl;
}