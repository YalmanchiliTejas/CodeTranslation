#include "bits/stdc++.h"

#define rep(i, a) for (int i = 0; i < (a); ++i)
#define REP(i, a, b) for (int i = a; i < (b); ++i)

#define vi vector<int>

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cerr << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << endl
#define debug_4(x1, x2, x3, x4) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define debug(...) CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) (__VA_ARGS__)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void Main() {
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i, n) cin>>a[i];
  vector<ll> sum(n+1, 0), dp(n+1, 0);
  rep(i, n) {
    if(i&1) sum[i+1]=sum[i];
    else sum[i+1]=sum[i]+a[i];
  }
  REP(i, 1, n) {
    if(i&1) dp[i+1]=max(dp[i-1]+a[i],sum[i]);
    else dp[i+1]=max(dp[i-1]+a[i],dp[i]);
  }
  cout<<dp[n]<<endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
