#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  if (k == 0) {
    ans = n * n;
  } else {
    for (ll b = 1; b < n + 1; b++) {
      ll cycle = n / b;
      ll amari = n % b;
      ll cnt_in_cycle = max(b - k, (ll)0);
      ll cnt_in_amari = max((amari + 1) - k, (ll)0);
      ans += cycle * cnt_in_cycle + cnt_in_amari;
    }
  }
  cout << ans << endl;
}