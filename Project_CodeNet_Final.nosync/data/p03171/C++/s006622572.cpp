#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  vector<vector<ll>> dp(n, vector<ll>(n));
  for(int L=n-1; L>=0; L--) {
    for(int R=L; R<n; R++) {
      if(L==R) {
        dp[L][R] = a[L];
      } else {
        dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
      }
    }
  }
  cout << dp[0][n-1] << '\n';


  return 0;
}