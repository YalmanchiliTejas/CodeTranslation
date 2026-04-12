#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
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
vecll tot(51, 0);
vecll p(51, 0);
ll rec(int i, ll k) {
  if (k == 0) return 0;
  if (i == 0) return 1;
  if (k == 1) return 0;
  // cout << i << " " << k << " " << (tot[i] + 1) / 2 << endl;
  if (k >= (tot[i] + 1) / 2) {
    return p[i - 1] + 1 + rec(i - 1, k - (tot[i] + 1) / 2);
  } else {
    return rec(i - 1, k - 1);
  }
}
int main() {
  init();
  int n;
  ll x;
  cin >> n >> x;
  tot[0] = p[0] = 1;
  REP(i, 50) {
    tot[i + 1] = 2 * tot[i] + 3;
    p[i + 1] = 2 * p[i] + 1;
  }
  // REP(i, 51) { cout << p[i] << endl; }
  // cout << tot[50] << end  l;
  // cout << p[50] << endl;
  cout << rec(n, x) << endl;
}
