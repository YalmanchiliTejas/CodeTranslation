#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  long long ans = 0;
  for(int b = 1; b <= N; ++b) {
    // cout << (N/b) * max(b-K, 0) << endl;
    // cout << max(0, (N%b)-K+1) << endl;
    ans += (N/b)*max(b-K, 0) + max(0, (N%b)-K+1);
  }
  if(K==0) ans -= N;
  cout << ans << endl;
}
