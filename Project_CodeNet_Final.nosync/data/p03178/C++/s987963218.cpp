//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const ll maxn = 2e5+100;
const ll K = 310;
const ll mod = 1e9+7;

ll n , m , k, d;
ll dp[maxn][K], f[maxn][K];
string s;

ll ds(ll x)
{
    ll ans = 0;
    while(x)
    {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main()
{
    cin>> s >> d; n = s.size();

    if(n <= 8)
    {
        ll x = 0, pw = 1;
        for(ll i = n-1; i >= 0; i--)
        {
            ll y = s[i]; y -= 48;
            x += pw * y;
            pw *= 10;
        }

        ll ans = 0;
        for(ll i = 1; i <= x; i++)
            if(ds(i) % d == 0)
                ans++;
        cout<< ans;
        return 0;
    }

    if(d == 1)
    {
        ll pw = 1, ans = 0;
        for(ll i = n-1; i >= 0; i--)
        {
            ll y = s[i]; y -= 48;
            ans = (ans + (pw*y) % mod) % mod;
            pw = (pw*10) % mod;
        }
        cout<< ans;
        return 0;
    }

	if(n == 1)
	{
		ll ans = 0;
		ll y = s[0]; y -= 48;
		for(ll i = 1; i <= y; i++)
			if(i % d == 0)
				ans++;
		cout<< ans;
		return 0;
	}
    for(ll i = n-1; i >= 0; i--)
        for(ll j = 0; j < d; j++)
        {
            if(i == n-1){
                for(ll ii = 0; ii < 10; ii++){
                    if((ii % d) == j)
                        f[i][j]++;
				}
			    continue;
            }
            for(ll ii = 0; ii < 10; ii++){
                ll x = (j-ii+10*d)%d;
                f[i][j] = (f[i][j] + f[i+1][x]) % mod;
            }
        }

    for(ll i = n-1; i >= 0; i--)
    {
        ll y = s[i]; y -= 48;
        for(ll j = 0; j < d; j++)
        {
            if(i == n-1){
                for(ll ii = 0; ii <= y; ii++)
                    if((ii % d) == j)
                        dp[i][j]++;
                continue;
            }

            for(ll ii = 0; ii < y; ii++){
                ll x = (j-ii+10*d)%d;
                dp[i][j] = (dp[i][j] + f[i+1][x]) % mod;
            }
            ll x = (j-y+10*d)%d;
            dp[i][j] = (dp[i][j] + dp[i+1][x]) % mod;
        }
    }

	dp[0][0] %= mod;
	if(dp[0][0] < 0)
		dp[0][0] += mod;

	if(dp[0][0] == 0)
		cout<< mod-1;
	else
		cout<< dp[0][0] - 1;
}





