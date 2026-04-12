//In The Name of Beauty
//...So here I go is my shot
//Feet fail me not 'cause maybe the only opportunity that I got...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define IB std::ios::sync_with_stdio(0);
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define F first
#define S second
ll const MAXN = 1e4 + 8;
ll const KAM  = 1e2 + 8;
ll const delta = 1000000007;
ll dp[MAXN][KAM];
int main()
{
    IB;
    cin.tie(0);
    cout.tie(0);
    string k;
    cin >> k;
    ll d;
    cin >> d;
    dp[0][0] = 1;
    for(ll i = 0;i < MAXN - 1;i++)
    {
        for(ll j = 0;j < d;j++)
        {
            for(ll k = 0;k < 10;k++)
            {
                dp[i + 1][(k + j) % d] = (dp[i + 1][(k + j) % d] + dp[i][j]) % delta;
            }
        }
    }
    ll ans = 0;
    ll temp = 0;
    for(ll i = 0;i < k.size();i++)
    {
        for(ll j = (k[i] - '0') - 1;j >= 0;j--)
        {
            ans = (ans + dp[k.size() - i - 1][(d - (temp + j) + d) % d]) % delta;
        }
        temp = (temp + (k[i] - '0')) % d;
    }
    if(temp % d != 0)ans = (ans - 1 + delta) % delta;
    cout << ans;
    return 0;
}
//Written by M_H_H_7
