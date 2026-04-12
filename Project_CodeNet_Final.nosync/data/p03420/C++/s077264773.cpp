#include <bits/stdc++.h>
#define pb push_back
#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define MOD 1000000007
#define INF 93193111451418101
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  ll n, k, ans = 0;
  cin >> n >> k;
  if (k == 0) {
    return !printf("%lld\n", n * n);
  }
  FOR(i, k + 1, n + 1) {
    // ll hoge = ans;
    ans += n / i * (i - k) + max((ll)0, n % i - k + 1);
    // cout << i << " " << ans - hoge << endl;
  }
  cout << ans << endl;
}
