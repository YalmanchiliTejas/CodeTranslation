#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;

  cin >> n;

  int table[n];

  for(int i=0; i < n; i++) {
    cin >> table[i];
  }
  int west = table[0];
  int ans = 0;
  int maxN = 0;

  for(int i=0; i<n; i++) {
    maxN = max(maxN,table[i]);
    
    if(table[i] >= maxN) {
      ans++;
    }
  }
  cout << ans << endl;
}