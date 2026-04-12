#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int max = 0;
  
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    if (h >= max) {
      max = h;
      ans++;
    }
  }
  
  cout << ans << endl;
  
}