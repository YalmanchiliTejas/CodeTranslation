#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc179/abc179_e.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N, X, M;
  cin >> N >> X >> M;

  unordered_map<ll, ll> m;
  vector<ll> c(M + 1, 0);

  ll ans = X;
  ll an = X;

  int start = -1, end = -1;
  c[0] = an;
  repi(i, 1, N) {
    an = (ll)(pow(an, 2)) % M;
    if (m.count(an)) {
      start = m[an];
      end = i;
      break;
    }
    ans += an;
    m.emplace(an, i);
    c[i] = an;
  }

  if (start != -1) {
    ll len = end - start;
    ll rest = (N - end) / len;
    ll mod = (N - end) % len;

    ll sum = 0;
    ll modsum = 0;
    int cnt = 0;
    repi(i, start, end) {
      sum += c[i];
      if (i - start < mod) modsum += c[i];
    }
    ans += sum * rest + modsum;
  }
  cout << ans << endl;
}