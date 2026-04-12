// And Then the GOD Entered..   
#include<bits/stdc++.h>
 using namespace std;
 
typedef long long int ll;
#define endl "\n"
#define fi first
#define sec second 
#define pb push_back
#define test cout<<"debuged\n";
#define INF ll(1e18)
#define MOD 1000000007
#define debug(x) cout<<x<<"\n";
#define pll pair<ll,ll>
#define mp make_pair
#define Minato_Namikaze ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define MAX 200015

ll k;
string s;
ll n;
ll dp[1000][4][2];

ll solve(ll idx, ll k, ll tight)
{
    if(idx == n)
    {
        if(k == 0)
            return 1;
        else
            return 0;
    }
    ll end = s[idx] - '0';
    if(tight)
    {
        end = 9;
    }
    ll &ans = dp[idx][k][tight];
    if(ans != -1)
        return ans;
    ans = 0;
    for(ll i = 0; i <= end; ++i)
    {
        if(i == 0)
        {
            if(i == end)
            {
                ans += solve(idx + 1, k, tight);
            }
            else
            {
                ans += solve(idx + 1, k, 1);
            }
        }
        else
        {
            if(k == 0)
                continue;
            if(i == end)
            {
                ans += solve(idx + 1, k - 1, tight);
            }
            else
            {
                ans += solve(idx + 1, k - 1, 1);
            }
        }
    }
    return ans;
}


int main()
{
    Minato_Namikaze
    
    memset(dp, - 1, sizeof dp);
    cin >> s >> k;
    n = (ll)s.size();
    ll ans = solve(0, k, 0);
    cout << ans << endl;
}