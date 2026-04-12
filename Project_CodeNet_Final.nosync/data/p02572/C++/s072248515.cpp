/*author @dhanush*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define se second
#define fi first

ll MOD = 1e9 + 7;

int main()
{



  ll n;
  cin >> n;
  ll arr[n];
  for (int i = 0; i < n; i++)cin >> arr[i];

  vector<ll>pref(n + 1);
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    pref[i] = (pref[i - 1] + arr[i - 1]);
  }
  ll ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    ll yy = pref[n] - pref[i + 1];
    ll xx = ((yy % MOD) * arr[i]) % MOD;
    ans = (ans + xx) % MOD;
  }
  cout << ans << endl;


}





