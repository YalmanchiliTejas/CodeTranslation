#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  cin >> H.at(0);
  int ans = 1;
  int max = H.at(0);
  for (int i = 1; i < N; i++) {
    cin >> H.at(i);
    if (H.at(i) >= max) {
      ans++;
      max = H.at(i);
    }
  }
  cout << ans << endl;
}
