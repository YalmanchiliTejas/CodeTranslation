#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> w;
  REP(i, n) {
    int a;
    cin >> a;
    int b = upper_bound(ALL(w), a, [](int l, int r) { return l > r; }) - w.begin();
    if (b == w.size()) {
      w.pb(a);
    } else {
      w[b] = a;
    }
  }
  int ans = w.size();
  cout << ans << endl;
  return 0;
}