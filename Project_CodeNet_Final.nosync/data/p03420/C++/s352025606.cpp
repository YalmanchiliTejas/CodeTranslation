#include <bits/stdc++.h>
using namespace std;
typedef signed long long lint;

mt19937 mt(time(nullptr));
// uniform_int_distribution< int > rand_int(0, 10) // rand[0, 10] inclusive

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  lint n, k;
  cin >> n >> k;
  lint ans = 0;
  for (lint b=k+1; b<=n; ++b) {
    // a%b >= k
    ans += n/b*(b-k);
    ans += max((lint)0, n%b-max(k-1, (lint)0));
  }
  cout << ans << endl;
  return 0;
}
