#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const ll MOD = 998244353;

ll add(ll x)
{
  return (x + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n, s, ans = 0;
    cin >> n >> s;
    vi dp(3010, 0);
    for (int  i =0 ; i < n; i++)
    {
        ll a;
        cin >> a;
        for (int j = s; j >= a; j--)
            dp[j] = add(dp[j] + dp[j - a]);    // add the number of sequences iteratively for each previous element  
        dp[0] += 1;
        dp[a] += 1;
        ans = add(dp[s] + ans);
    }
    cout << (ans + MOD) % MOD << endl;
    return 0;
}
