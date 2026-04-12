#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n;
  cin >> n;
  vector<ll> cnt(26, 1e18);
  REP(i, n) {
    string s;
    cin >> s;
    vector<ll> tmp(26, 0);
    for (char c : s) {
      ll x = c - 'a';
      tmp[x]++;
    }
    REP(i, 26) { cnt[i] = min(cnt[i], tmp[i]); }
  }

  REP(i, 26) {
    REP(j, cnt[i]) { cout << (char)('a' + i); }
  }
  cout << endl;
}