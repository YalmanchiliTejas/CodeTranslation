//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const ll maxn = 5e3+10;
const ll mod = 1e9+7;

ll n , m , k;
ll dp[maxn][maxn], a[maxn];

int main()
{
    cin>> n;
    for(ll i = 1; i <= n; i++) cin>>  a[i];

    for(ll t = 1; t <= n; t++)
        for(ll l = 1; l+t-1 <= n; l++)
        {
            ll r = l+t-1;
            if(t == 1){
                dp[l][r] = a[l];
                continue;
            }

            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    cout<< dp[1][n];
}








