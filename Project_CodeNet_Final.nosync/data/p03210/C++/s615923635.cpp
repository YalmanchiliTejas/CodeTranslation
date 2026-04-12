#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

int main() {
  int n; cin >> n;

  string ans;
  if(n == 3 || n == 5 || n == 7) ans = "YES";
  else ans = "NO";

  cout << ans << endl;

  return 0;
}
