#include<bits/stdc++.h>
#define ll long long
#define f   first
#define s   second
#define pb          push_back
#define mod         1000000007
#define hell        998244353
#define inf         1000000000000000000LL
using namespace std;
ll n,k,m;
//ll dp[15][1005];
ll fen[20005];
void update(ll x,ll val)
{
    for(int i=x;i<=n;i+=(i&-i))
        fen[i]+=val;
}
ll query(ll x)
{
    ll sum=0;
    for(;x>0;x-=(x&-x))
        sum+=fen[x];
    return sum;

}
ll bs(ll sum)
{   //hcout<<query(2);
    //cout<<sum;
    ll l=0,h=n;  
    while(h>l+1)
    {   ll mid=(l+h)/2;
        //cout<<l<<mid<<h<<query(mid)<<" ";
        ll x=query(mid);
        if(x>=sum) h=mid;
        else l=mid;
        

    }
    //cout<<l<<h<<" ";
    if(query(l)==sum) return l;
    else return h;
}
void solve()
{   
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j) dp[i][j]=v[i];
            else dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];

    
}

int main()
{
    ll t=1;
    //cin>>t;
    while(t--)
        solve();

}