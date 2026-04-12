#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int ans = 1;
  int M;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  M = H.at(0);
  for (int i = 1; i < N; i++) {
    if (M <= H.at(i)) {
      ans++;
      M = H.at(i); 
    }
  }
  cout << ans << endl;
}