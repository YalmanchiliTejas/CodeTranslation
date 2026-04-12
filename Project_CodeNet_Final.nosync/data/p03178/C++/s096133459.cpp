#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
 ll n , k;
ll dp[100002][101][2];
string num;

ll func(ll pos , ll N , ll f , ll sum)
{
    if(pos == N)
    {
           
        if(sum%k == 0)
        {
            return 1;
        }
        return 0;
    }

    if(dp[pos][sum][f] != -1 && f == 0)
    {
        return dp[pos][sum][f]%mod;
    }

    ll limit ;
    if(f == 1)
    limit = num[pos]-48;
    else
    limit = 9;
    ll ans = 0;
    for(ll i = 0 ; i <= limit ; i++)
    {
        ll nf = f;
        if(i != limit)
        nf = 0;
        ll new_sum =(sum + i)%k;
       ans = (ans%mod + func(pos+1 , N , nf , new_sum )%mod)%mod;
    }

    dp[pos][sum][f] = ans;
    return ans;
}

int main() {
    cin >> num;
    cin >> k;
    ll N = 0 ;
    ll temp = n;
    for(ll i = 0 ; i <= 100001 ; i++)
    {
        for(ll j = 0 ; j <= 100 ; j++)
        dp[i][j][0] = -1 , dp[i][j][1] = -1;
    }
    N = num.size();

 
    ll ans = (func(0, N , 1 , 0)-1);
    if(ans < 0)
    ans += mod;

    cout << ans;
}
