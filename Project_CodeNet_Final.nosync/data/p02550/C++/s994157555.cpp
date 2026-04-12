#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))

#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed

bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, X, M;
  cin >> N >> X >> M;

  // main procedure
  unordered_set<ll> Xs;
  vector<ll> Xv;
  Xs.insert(X);
  Xv.push_back(X);

  ll x = X;
  ll i = 1;
  ll j = 0;
  vector<ll> s;
  s.push_back(X);
  while (i < N) {
    x = (x * x) % M;
    if (Xs.count(x) != 0) {
      j = distance(Xv.begin(), find(ALL(Xv), x));
      break;
    } else {
      Xs.insert(x);
      Xv.push_back(x);
      s.push_back(s.back() + x);
    }
    i++;
  }

  ll sj = (j != 0 ? s[j - 1] : 0);
  ll r = (N - j) % (i - j);
  ll ans =
      (s.back() - sj) * ((N - j) / (i - j)) + (j + r != 0 ? s[j + r - 1] : 0);

  // output
  cout << ans << endl;

  return 0;
}