#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0;
  cin >> n;
  
  int cnt = 0;
  int MAX = 0;
  
  vector<int> H(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> H[i];
    if (H[i] >= MAX) {
      cnt++;
      MAX = H[i];
    }
  }
  
  cout << cnt << endl;
  
}