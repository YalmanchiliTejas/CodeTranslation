#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans = 0, max;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
    if (i == 0) {
      ans++;
      max = H.at(i);
    }
    else if(max <= H.at(i)) {
      ans++;
      max = H.at(i);
    }   
  }
  cout << ans << endl;
}