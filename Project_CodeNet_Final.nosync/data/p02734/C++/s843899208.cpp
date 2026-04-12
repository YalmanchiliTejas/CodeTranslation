/*

            ░   ▒▓█  𝕿𝖆𝖑𝖐 𝖎𝖘 𝖈𝖍𝖊𝖆𝖕. 𝕾𝖍𝖔𝖜 𝖒𝖊 𝖙𝖍𝖊 𝖈𝖔𝖉𝖊 █▓▒░
   */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define ld long double
#define si(x) (ll)((x).size())
#define pb push_back
#define F first
#define S second
#define rep(i,n) for(ll i=0;i<n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per1(i,n) for(ll i=n;i>=1;i--)
#define all(x) (x).begin(), (x).end()
#define make_unique(x) (x).resize(unique(all(x))-(x).begin())
#define pr_vec(v) for(ll _=0;_<v.size();_++) cout << v[_] << " " ;
const int N = 1e6 + 7;
ll m = 998244353;



void solve()
{
    ll n, s, x, ans = 0;
    cin >> n >> s;

    std::vector<ll> dp(s + 1);
    rep(_, n)
    {
        dp[0] += 1;
        cin >> x;
        for(ll j = s - x; j >= 0; j--)
            (dp[j + x] += dp[j]) %= m;

        (ans += dp[s]) %= m;

    }
    cout << ans;



}





int main()
{



    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;


    rep1(i, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // cout << endl;
    }


}