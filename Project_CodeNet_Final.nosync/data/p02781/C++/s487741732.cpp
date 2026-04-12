#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // dpPend と dpOkを0〜Kまで保持
  string N;
  int K;
  cin >> N >> K;
  vector<int> dpPend(K+1);
  vector<int> dpOk(K+1);
  dpPend[0] = 1;
  for (char n : N) {
    int cur = n - '0';
    if (cur == 0) {
      //vector<int> prevPend(K+1);
      vector<int> prevOk = dpOk;
      //swap(dpPend, prevPend);
      for (int i = K; i > 0; i--) {
        //dpPend[i] = prevPend[i-1];
        dpOk[i] += 9 * prevOk[i-1];
      }
    } else {
      // 1〜9の間
      vector<int> prevPend(K+1);
      vector<int> prevOk(K+1);
      swap(dpPend, prevPend);
      swap(dpOk, prevOk);
      for (int i = K; i >= 0; i--) {
        if (i == 0) {
          dpOk[i] = prevOk[i] + prevPend[i];
        } else {
          dpPend[i] = prevPend[i-1];
          dpOk[i] = prevOk[i] + 9 * prevOk[i-1] + prevPend[i] + (cur-1) * prevPend[i-1];
        }
      }
    }
  }
  ll ans = dpPend[K] + dpOk[K];
  cout << ans << '\n';  
  return 0;
}