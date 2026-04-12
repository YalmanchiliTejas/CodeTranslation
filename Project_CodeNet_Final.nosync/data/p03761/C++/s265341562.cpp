#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  string s[n];
  REP(i, n) cin >> s[i];
  int a[n][26];
  REP(i, n) REP(j, 26) a[i][j] = 0;
  REP(i, n) REP(j, s[i].size()) { a[i][s[i][j] - 'a']++; }
  int ans[26];
  REP(i, 26) ans[i] = 100;
  REP(i, 26) REP(j, n) { ans[i] = min(ans[i], a[j][i]); }
  REP(i, 26) REP(j, ans[i]) cout << (char)(i + 'a');
  cout << "\n";
  return 0;
}