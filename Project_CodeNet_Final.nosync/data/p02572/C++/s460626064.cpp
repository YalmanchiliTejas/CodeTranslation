#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,c,m;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll sum[n];
    ll temp=arr[n-1];
    for(i=n-1;i>=1;i--)
    {
        sum[i]=temp;
        temp+=arr[i-1];
    }
    sum[0]=0;
    //for(i=0;i<n;i++) cout<<sum[i]<<" ";
    ll ans=0;
    for(i=0;i<n-1;i++)
    {
        ans+=((arr[i]%1000000007)*(sum[i+1]%1000000007))%1000000007;
    }
    cout<<ans%1000000007;
    
}