#include <bits/stdc++.h>
#define endl '\n'
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define IT set<node>::iterator
#define mem(a) memset(a,0,sizeof(a))
typedef long long LL;
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
ll a[N], sum[N];
int main() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i], sum[i] %= mod;
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += (a[i] * ((sum[n] - sum[i] + mod) % mod)) % mod;
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
