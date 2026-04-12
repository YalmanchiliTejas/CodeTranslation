/*
  KUNAL ANAND
  MNNIT ALLAHABAD
*/  

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<assert.h>
using namespace std;
using namespace __gnu_pbds;
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long int ll;
const ll INF=1e16;
const ll mod=1e9+7;

ll power(ll x,ll y)
{
    if(y==0)
        return 1;
    ll a=power(x,y/2);
    a=(a*a)%mod;
    if(y%2)
        a=(a*x%mod)%mod;
    return a;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    ll n,q;
    ll i,j,k,a,b,m,c=1,ans1=0,ans2=0,x1,x2,y2,y1,s,mini=LLONG_MAX,idx,ans=0,l;

    string num;

    cin >> num;

    cin >> k;

    vector<ll>helper;

    n=num.length();

    for(i=0;i<n;i++)
    {
        helper.push_back(num[i]-'0');
    }

    ll dp[n+1][k];

    memset(dp,0,sizeof(dp));

    dp[0][0]=1;

    for(i=1;i<n;i++)
    {
        for(j=1;j<10;j++)
        {
            for(l=0;l<k;l++)
            {
                ll x=(j%k+l)%k;
                dp[i][x]+=dp[i-1][l];
                dp[i][x]%=mod;
            }
        }

        ans+=dp[i][0];
        ans%=mod;

        for(l=0;l<k;l++)
        {
            dp[i][l]+=dp[i-1][l];
            dp[i][l]%=mod;
        }
    }

    ll var=0;

    ll cnt=0;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {    
            for(j=1;j<helper[i];j++)
            {
                for(l=0;l<k;l++)
                {
                    ll x=(j%k+l)%k;
                    x+=var;
                    x%=k;
                    dp[n][x]+=dp[n-i-1][l];
                    dp[n][x]%=mod;
                }
            }
        }
        else
        {
            for(j=0;j<helper[i];j++)
            {
                for(l=0;l<k;l++)
                {
                    ll x=(j%k+l)%k;
                    x+=var;
                    x%=k;
                    dp[n][x]+=dp[n-i-1][l];
                    dp[n][x]%=mod;
                }
            }
        }

        var+=helper[i];
        var%=k;
    }

    dp[n][var%k]++;

    ans+=dp[n][0];
    ans%=mod;

    cout << ans << endl;



    return 0;
}    