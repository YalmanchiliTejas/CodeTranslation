#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;

int main() {
  string s;
  cin >> s;
  bool a = false, b = false;
  REP(i, 3) {
    if (s[i] == 'A') a = true;
    if (s[i] == 'B') b = true;
  }
  if (a && b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}