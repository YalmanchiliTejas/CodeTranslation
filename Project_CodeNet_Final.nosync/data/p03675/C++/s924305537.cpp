#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, m, n) for (int i = m; i <= n; ++i)

using i64 = long long;
using pii = pair<i64, i64>;

template<class A, class B>inline bool chmax(A &a, const B &b){return b > a ? a = b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b < a ? a = b,1 : 0;}

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int MOD = int(1e9) + 7;

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n+1);
  reps(i, 1, n) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << a[1] << "\n";
    return 0;
  }

  vector<int> first;
  vector<int> second;

  if (n % 2 != 0) {
    reps(i, 1, n) {
      if (i % 2 != 0) first.push_back(a[i]);
      else second.push_back(a[i]);
    }
  }

  else {
    reps(i, 1, n) {
      if (i % 2 == 0) first.push_back(a[i]);
      else second.push_back(a[i]);
    }
  }

  reverse(all(first));

  for (int i = 0; i < first.size(); ++i) {
    cout << first[i] << ' ';
  }

  for (int i = 0; i < second.size(); ++i) {
    cout << second[i] << " \n"[i==second.size()-1];
  }

  return 0;
}