#include<bits/stdc++.h>

using namespace std;

static const int INF = 1e9 + 7;

void hawawa()
{
  long long k, a, b;
  cin >> k >> a >> b;
  long long ans = 1;
  k -= a;
  if (k <= 0) {
    cout << ans << "\n";
    return;
  }
  if (a > b) {
    a -= b;
    ans += (k / a + !!(k % a)) * 2;
    cout << ans << "\n";
  } else {
    cout << "-1\n";
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  hawawa();
}