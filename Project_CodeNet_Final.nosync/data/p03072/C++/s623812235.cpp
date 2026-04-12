#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n-(n-i-1); j++) {
      if(h.at(i) < h.at(j)) {
         ans--;
        goto p;
      }
    }
    p:;
  }
  cout << ans;
}