#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  int ans = 0;
  cin >> N;
  vector<int> H(N);
  REP(i, N) cin >> H[i];
  for(int i = 0; i < N; i++) {
    //うみみれる
    bool flag = true;
    for(int j = 0; j < i; j++) {
      if(H[j] > H[i]) {
        flag = false;
        break;
      }
    }
    if(flag) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}