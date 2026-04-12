#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define all(v) v.begin(),v.end()
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

ll power(ll a, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main()
{
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    repf(i,0,n) cin>>a[i];
    ll dp[n][n];
    // repf(i,0,n)
    // {
    //     repf(j,0,n)
    //     {
            
    //     }
    // }
    repb(i,n-1,0)
    {
        repf(j,i,n)
        {
            if(i==j) dp[i][j]=(n%2?a[i]:-a[i]);
            else if(i+1==j) dp[i][j]=max(a[i]-a[j],a[j]-a[i]);
            else
            {
                ll x=a[i]+min(-a[i+1]+dp[i+2][j],-a[j]+dp[i+1][j-1]);
                ll y=a[j]+min(-a[i]+dp[i+1][j-1],-a[j-1]+dp[i][j-2]);
                dp[i][j]=max(x,y);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;  
}