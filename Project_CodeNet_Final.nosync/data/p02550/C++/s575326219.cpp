#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  ll N, X, M;
  cin >> N >> X >> M;
  unordered_map<ll, ll> uo;
  vector<ll> mod(M, -1);
  ll ans = 0;
  bool b = false;
  ll tmp = X;
  if (M == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = 1; i <= N; i++) {
    if (mod[tmp] != -1 && !b) {
      ll t = i - mod[tmp];
      ll num = 0;
      for (ll j = mod[tmp]; j < i; j++) {
        num += uo[j];
      }
      ll d = N - (mod[tmp] );
      ans += (d / t - 1) * num;
      // i = N - d % t - mod[tmp];
      /*i = N;
      i -= d % t;
      i -= mod[tmp];*/
      i += (d / t - 1) * t;
      b = true;
    }
    ans += tmp;
    uo[i] = tmp;
    mod[tmp] = i;
    tmp *= tmp;
    tmp %= M;
    if (tmp == 0) break;
  }
  cout << ans << endl;
}