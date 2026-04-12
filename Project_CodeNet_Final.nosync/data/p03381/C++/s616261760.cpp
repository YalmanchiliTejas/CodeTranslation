#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;
ul over = 1000000007;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  ul n;
  cin >> n;
  vector< tuple< ul, ul > > v(n);
  for (ul i=0; i<n; ++i) {
    ul x;
    cin >> x;
    v[i] = make_tuple(x, i);
  }
  sort(v.begin(), v.end());
  ul x1 = get<0>(v[n/2-1]), x2 = get<0>(v[n/2]);
  vector< ul > ans(n);
  for (ul i=0; i<n; ++i) {
    ans[get<1>(v[i])] = (i < n/2 ? x2 : x1);
  }
  for (ul i=0; i<n; ++i) cout << ans[i] << endl;
  return 0;
}
