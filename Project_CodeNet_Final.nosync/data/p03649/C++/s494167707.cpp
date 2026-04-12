#include <bits/stdc++.h>

#define FOR(i, a, b)  for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << "\n"
#define _ << " _ " <<
#define ll long long

using namespace std;

vector <ll> ve;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) {
    ll a;
    cin >> a;
    ve.push_back(a);
  }

  ll out = 0;
  while (1) {
    sort(ve.begin(), ve.end());
    if (ve[n - 1] <= (ll) (n - 1)) {break;}

    ll tr = ve[n - 1] - (ll) (n - 1);
    ll num = (tr / (ll) n);
    if (tr % (ll) n) {num += 1LL;}
    REP(i, n - 1) ve[i] += num;
    ve[n - 1] -= (num * (ll) n);
    out += num;
  }
  cout << out << endl;

  return 0;
}
