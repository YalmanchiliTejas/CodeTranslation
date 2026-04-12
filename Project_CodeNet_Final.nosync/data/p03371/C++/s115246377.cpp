#include <bits/stdc++.h>
#define REP(i, n) for (decltype(n) i = 0; i < n; i++)
#define REPvec(itr, mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007  // 1e9+7
using namespace std;
typedef long long int ll;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef vector<double> vecd;
typedef vector<string> vecstr;
typedef vector<char> vecchar;
typedef vector<bool> vecbool;
typedef vector<vector<bool>> vec2bool;
typedef vector<vector<int>> vec2int;
typedef vector<vector<double>> vec2d;
////////////////////////////////////////////////
void init() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
////////////////////////////////////////////////
int main() {
  init();
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  int ans = a * x + b * y;
  int a1 = c * y + a * max(0, x - y);
  int a2 = c * x + b * max(0, y - x);
  ans = min({ans, a1, a2});
  cout << ans << endl;
}