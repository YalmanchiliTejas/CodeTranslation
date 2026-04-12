#include "bits/stdc++.h"

#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (long i = (a); i <= (b); ++i)
#define per(i, a, b) for (long i = (a); i >= (b); --i)
#define mmst(v) memset(v, 0, sizeof(v))

const long kMax2 = 109;
const long kMax3 = 1009;
const long kMax4 = 10009;
const long kMax5 = 100009;
const long kMax6 = 1000009;
const long kInfI = 0x3F3F3F3F;
const float kInfF = 1e15;

using namespace std;
using ll = long long;

void solve() {
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  int dplen = 0;
  int dp[kMax5];
  vector<int> a;
  cin >> n;
  rep(i, 0, n - 1) {
    int a_i;
    cin >> a_i;
    a.pb(kInfI - a_i);
  }

  mmst(dp);

  rep(i, 0, n - 1) {
    int idx = upper_bound(dp, dp + dplen, a[i]) - dp;
    dp[idx] = a[i];
    if (idx + 1 > dplen) {
        dplen = idx + 1;
    }
  }

  cout << dplen << endl;

  return 0;
}
