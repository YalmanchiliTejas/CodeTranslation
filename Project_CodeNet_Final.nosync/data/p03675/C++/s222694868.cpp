#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i >= n; --i)
typedef long long ll;
#define mod 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  vector<int> e, o;
  rep(i, 0, N) {
    if(i & 1) e.push_back(a[i]);
    else o.push_back(a[i]);
  }
  if(N & 1) {
    reverse(o.begin(),o.end());
    rep(i, 0, o.size()) cout << o[i] << " ";
    rep(i, 0 ,e.size()) cout << e[i] << " ";
  } else {
    reverse(e.begin(),e.end());
    rep(i, 0, e.size()) cout << e[i] << " ";
    rep(i, 0 ,o.size()) cout << o[i] << " ";
  }
  cout << endl;
  return 0;
}
