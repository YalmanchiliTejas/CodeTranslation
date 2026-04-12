#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const long double PI = acos(-1.0L);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s = "abc";
  rep(i, 3) cin >> s[i];
  int n = stoi(s);
  if (n%4)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}