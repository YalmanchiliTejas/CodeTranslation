#include<bits/stdc++.h>
using namespace std;

signed main(){
  int N, K; cin >> N >> K;
  long long ans = 0;
  for(int b = 1; b <= N; b++){
    int p = N/b;
    int r = N - p*b + 1;
    ans += (p * max(0, b - K) + max(0, r - K)) - (K == 0);
  }
  cout << ans << endl;
}
