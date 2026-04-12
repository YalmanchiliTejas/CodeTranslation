#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> ar;
const ll MAX = 3010;
vector<vector<ll>> dp(MAX, vector<ll>(MAX, -1));

ll ans = 0;
ll func(ll s, ll e)
{
    if (s > e)
    {
        return 0;
    }
    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }
    else
    {
        dp[s][e] = max(ar[s] - func(s + 1, e), ar[e] - func(s, e - 1));
        return dp[s][e];
    }
}
int main()
{
    ll n;
    cin >> n;
    ar = vector<ll>(n);
    for (int x = 0; x < n; x++)
    {
        cin >> ar[x];
    }
    ll s = 0, e = n - 1;
    ll score = 0;
    func(s, e);
    cout << dp[s][e] << endl;
}