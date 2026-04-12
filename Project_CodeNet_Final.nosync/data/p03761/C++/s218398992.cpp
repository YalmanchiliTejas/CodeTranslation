#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  vl a(26, 1e9);
  rep(i, n) {
    string s;
    cin >> s;
    vl b(26, 0);
    rep(j, s.size()) b[s[j] - 'a']++;
    rep(j, 26) a[j] = min(a[j], b[j]);
  }
  rep(i, 26) rep(j, a[i]) cout << char(i + 'a');
  cout << endl;
}