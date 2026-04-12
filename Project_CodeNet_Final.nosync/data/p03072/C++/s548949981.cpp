#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N);
  ll m = 0;
  ll ret = 0;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
    if(H[i] >= m){
      ret++;
      m = H[i];
    }
  }
  cout << ret << endl;
}
