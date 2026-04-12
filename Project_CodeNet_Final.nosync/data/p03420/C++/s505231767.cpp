#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, K;
  cin >> N >> K;
  long ans = 0;
  for(int i = 1; i <= N; i++){
    if(K >= i)continue;
    if(N % i != 0)ans += (N / i) * (i - K) + max((N % i - (K?K - 1:K)), 0L);
    else ans += (N / i) * (i - K);
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}