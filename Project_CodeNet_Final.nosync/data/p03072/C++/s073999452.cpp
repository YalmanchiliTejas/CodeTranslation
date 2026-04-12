#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int ans = 1;
  for (int i = 1; i < n; i++){
    int max_h = 0;
    for (int j = 0; j < i; j++) {
      max_h = max(max_h, h[j]);
    }
    if(h[i] >= max_h){
      ans++;
    }
  }
  cout << ans << endl;
}
