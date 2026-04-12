#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x=0,y,sum=0,p=0,l,k;
    cin>>n;
    int a[n],b[n+1];
    for(i=0;i<n;i++) cin>>a[i] , sum+=a[i];
    b[n]=0;
    for(i=n-1;i>=0;i--)
    {
        b[i]=b[i+1]+a[i];
    }
    //for(i=0;i<n;i++) cout<<b[i]<<' ';
    for(i=1;i<n;i++)
    {
        x+=((a[i-1]%mod)*(b[i]%mod))%mod;
    }
    cout<<x%mod;
    return 0;
}