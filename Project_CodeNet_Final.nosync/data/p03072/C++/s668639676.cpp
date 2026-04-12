#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  int h[n];
  REP(i,n) cin >> h[i];
  
  int m = h[0];
  int ans = 0;
  REP(i,n) {
    if (h[i] >= m) {
      ans++;
      m = h[i];
    }
  }
  
  cout << ans << endl;
  
}