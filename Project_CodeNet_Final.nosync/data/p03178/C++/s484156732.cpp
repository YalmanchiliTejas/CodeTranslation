/*
    author: kartik8800
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x 
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[10001][101][2];
ll solve(string& k, int& D, int pos, int d, bool tight)
{
    if(dp[pos][d][tight] != -1)
        return dp[pos][d][tight];
    int ub = (tight) ? (k[pos] - '0') : 9;
    if(pos == k.length() - 1)
    {
        ll ans = 0;
        for(int x = 0; x <= ub; x++)
            if(x%D == d)
                ans++;
        return ans;
    }
    ll ans = 0;
    for(int x = 0; x <= ub; x++)
        ans = (ans + solve(k, D, pos+1, (D+d-x%D)%D, tight && (x == ub))) % mod;
    return dp[pos][d][tight] = ans;    
}

int main() {
   int D;
   string k;
   cin >> k;
   cin >> D;
   memset(dp, -1, sizeof dp);
   cout << (mod + solve(k, D, 0, 0, 1) - 1) % mod;
   return 0;
}
