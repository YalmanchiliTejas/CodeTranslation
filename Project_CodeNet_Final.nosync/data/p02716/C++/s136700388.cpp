#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 1000000006
#define TEMPMOD1 998244353
#define TEMPMOD2 998244352
#define INF 1000000000000000007
#define NEGINF -1000000000000000007
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define plll pair<ll,pll>
#define vpll vector<pll>
using namespace std;
typedef long long int ll;

map<pll,ll> dp;

ll arr1[200010];

ll evaluate(ll items,ll left)
{
    if(dp.find({items,left})!=dp.end())
    {
        return dp[{items,left}];
    }
    if(items <= 0)
    {
        if(left==0)
            return 0;
        else
            return NEGINF;
    }
    ll val1=(items/2)-1;
    ll val2=(items+1)/2;
    if(left<val1 || left>val2)
    {
        return NEGINF;
    }
    ll ans=evaluate(items-1,left);
    ans=max(ans,evaluate(items-2,left-1)+arr1[items]);
    dp[{items,left}] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr1[i];
    }
    ll val= n/2;
    ll ans = evaluate(n,val);
    cout<<ans;
    return 0;
}
    