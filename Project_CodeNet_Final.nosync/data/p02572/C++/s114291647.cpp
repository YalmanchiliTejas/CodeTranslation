#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define deb(a) cout << a << ": "
using namespace std;
const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int md = 1e9 + 7;
int a[N], p[N];
int mul(int a, int b) {
  return ((a % md) * (b % md)) % md;
}
int add(int a, int b) {
  return ((a % md) + (b % md)) % md;
}
void sliczny() {
  int n;
  int ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  p[n] = a[n];
  for(int i = n; i > 0; i--) {
    p[i - 1] = a[i - 1] + p[i];
  }
  for(int i = 1; i < n; i++) {
    int cur = mul(a[i], p[i + 1]);
    ans = add(ans, cur);
  }
  cout << ans;
}

int32_t main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  //cin >> T; 
  for(int t = 1; t <= T; t++) {
    //cout << "Case #" << t << ": ";
    sliczny();
  }
  return 0;
}
