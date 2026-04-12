#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N;
  cin >> N;
  vector<int>vec(N);
  vector<int>sum(N+1);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    sum[i+1] += sum[i]+vec[i];
  }
  int ans = 0,san = sum[N];
  for(int i=0; i<N; i++){
    ans += vec[i]*((san-sum[i+1])%1000000007)%1000000007;
  }
  cout << ans%1000000007 << endl;
}
