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
  int n, k;
  cin >> n >> k;
  ul ans = 0;
  for (int b=k+1; b<=n; ++b) {
    ans += n/b * (b-k);
    if (n%b!=0) {
      ans += max(0, n-(n/b*b)-max(0, k-1));
    }
  }
  cout << ans << endl;
  return 0;
}
