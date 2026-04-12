// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define bp __builtin_popcountll
const int N = 105;
string s;
ll k;
ll dp[N][N][2];

ll solve(ll id,ll tot,ll chk)
{
    if(id==s.size())
    {
        if(tot==k)  return 1;
        else        return 0;
    }
    ll ans = dp[id][tot][chk];
    if(ans!=-1)   return ans;
    ans = 0;
    if(chk==1)
    {
        for(ll i=0;i<s[id]-'0';i++)
        {
            if(i==0)
            {
                ans = ans + solve(id+1,tot,0);
            }
            else       ans += solve(id+1,tot+1,0);
        }
        if(s[id]=='0')    ans = ans + solve(id+1,tot,1);
        else             ans += solve(id+1,tot+1,1);
    }
    else
    {
        for(ll i=0;i<=9;i++)
        {
            if(i==0)   ans += solve(id+1,tot,0);
            else       ans += solve(id+1,tot+1,0);
        }
    }
    dp[id][tot][chk] = ans;
    return ans;
}
int main()
{
    cin >> s >> k;
    memset(dp,-1,sizeof(dp));
    ll ans = solve(0,0,1);
    cout<<ans;
}