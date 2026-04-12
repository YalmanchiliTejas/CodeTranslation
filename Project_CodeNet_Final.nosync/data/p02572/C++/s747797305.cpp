#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(a,b) for(int i=a;i<b;i++)
#define nl "\n"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  ll a[n];
  ll sum = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n - 1; i++)
  {
    sum -= a[i];
    ans = (ans % MOD1 + ((sum % MOD1) * (a[i] % MOD1)) % MOD1) % MOD1;
  }
  cout << ans;
  return 0;
}

