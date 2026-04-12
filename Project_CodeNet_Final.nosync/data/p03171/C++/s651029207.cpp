#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll const mod = 1e9+7;
ll const N = 50;
ll const inf = 2e16;
#define UNASSIGNED -1
ll n0,k0;
pair<ll,ll>  dp[3002][3002];
bool mark[3002][3002];
pair<ll,ll> fun(ll arr[],ll s,ll e,ll play)
{
    if(s>e) 
    {
        return make_pair(0,0);
    }
    if(mark[s][e]!=0) return dp[s][e];
    pair<ll,ll> a,b,c;
    a=fun(arr,s+1,e,(play+1)%2);
    b=fun(arr,s,e-1,(play+1)%2);
    
    if(play==0)
    {
        
    if(a.first+arr[s]>b.first+arr[e])
    {
        c=a;
        c.first+=arr[s];
    }
    else
    {
        c=b;
        c.first+=arr[e];
        
    }
    
    }
    else
    {
        
    if(a.second+arr[s]>b.second+arr[e])
    {
        c=a;
        c.second+=arr[s];
    }
    else
    {
        c=b;
        c.second+=arr[e];
        
    }
    
    }
    //cout<<play<<" "<<c.first<<" "<< c.second<<"\n";
    
    mark[s][e]=1;
    dp[s][e]=c; 
    return dp[s][e];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,c,d,e,f,x,n,m,p,k,t,q;
    t=1;
    //cin>>t;
    //string s1,s2,s3;
    //simpleprime(sqrt(1000000000)+1);
	for(ll t0=0;t0<t;t0++)
    {
        cin>>n;
        memset(mark,0,sizeof(mark));
        n0=n;
        k0=k;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        
        pair<ll,ll> a11=fun(arr,0,n-1,0);
        
        cout<<a11.first-a11.second;
    }
    return 0;
}
