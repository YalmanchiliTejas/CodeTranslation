//control+option+n to run!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define NEGFOR(i, a, b) for (ll i = (a); i > (b); i--)
#define vll vector<long long>
#define sll set<long long>
#define ld long double
#define inf 1000000000000000000;
#define mll multiset<long long>
#define nn << "\n"
#define F(i, b) for (ll i = 0; i < b; i++)
//10^8 operations per second
//greatest int is 2,147,483,647
//greates long long is 9.22337204e18

//ALL FUNCTIONS SHOULD BE LL!!!!
ll mod = (ll)(1e9+7);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vll v(n);
  vll prefix = {0};
  FOR(i, 0, n)
  {
    cin >> v[i];
    v[i] %= mod;
    prefix.pb((v[i]%mod + prefix[prefix.size()-1]%mod) % mod);
  }

  ll ans = 0;
  ll sum = prefix[n]%mod;
  FOR(i, 0, n)
  {
    ans += (v[i] * ((sum - prefix[i + 1]+mod*mod)%mod)) % mod;
    ans %= mod;
  }
  cout << ans;


  cout << "\n"; //GET RID OF THIS FOR THE ACTUAL PROGRAM!!!!
}
