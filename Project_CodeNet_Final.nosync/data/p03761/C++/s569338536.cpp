#include <bits/stdc++.h>
using namespace std;

using LL = long long;

#define ALL(a) begin((a)), end((a))
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); (i)--)
#define debug(x) cerr << #x << " : " << x << '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const LL LINF = 1e16;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string ans = "";
  int n;
  cin >> n;
  vector<vector<int>> count(n, vector<int>(26));
  string S;

  FOR(i, 0, n) {
    cin >> S;
    int size = S.size();

    FOR(j, 0, size) {
      int num = (int)(S[j] - 'a');
      count[i][num]++;
    }
  }

  FOR(i, 0, 26) {
    int minimum = 100;

    FOR(j, 0, n) { minimum = min(minimum, count[j][i]); }

    FOR(j, 0, minimum) {
      char ch = 'a' + i;
      ans.push_back(ch);
    }
  }

  cout << ans << '\n';

  return 0;
}