#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  for (int i=0; i<n; i++) cin >> A[i];

  if (n%2 == 0) {
    ll dp0 = 0, dp1 = 0;
    for (int i=0; i<n; i++) {
      if (i%2 == 0) {
        dp1 = max(dp0, dp1);
        dp0 += A[i];
      }
      else {
        dp1 += A[i];
      }
    }
    cout << max(dp0, dp1) << endl;

  }
  else {
    ll dp0 = 0, dp1 = 0, dp2 = 0;
    for (int i=0; i<n; i++) {
      if (i%2 == 0) {
        dp1 = max(dp0, dp1);
        if (i != n-1) dp0 += A[i];
        if (i != 0) dp2 += A[i];
      }
      else {
        dp2 = max(dp1, dp2);
        dp1 += A[i];
      }
    }
    cout << max(max(dp0, dp1), dp2) << endl;
  }

  return 0;
}