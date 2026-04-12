#include <bits/stdc++.h>
using namespace std;

int ans(int N, vector<int> H) {
  int a = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (a <= H.at(i)) {
      ans++;
      a = H.at(i);
    }
  }
  return ans;
}
 
int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  cout << ans(N, H) << endl;
}