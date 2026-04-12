#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  const string alphabet = "abcdefghijklmnopqrstuvwxyz";
  map<char, int> num;
  rep(j,26) num[alphabet[j]] = j;

  Graph counter(n, vi(26));
  rep(i,n) for (auto c : s[i]) ++counter[i][num[c]];

  vi ans(26, 51);
  rep(j,26) rep(i,n) ans[j] = min(ans[j], counter[i][j]);

  rep(j,26) rep(i,ans[j]) cout << alphabet[j];
  cout << endl;
  return 0;
}
