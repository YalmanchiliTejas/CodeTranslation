#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int modinverse(int a, int m=mod) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    {
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int a[n],i,sum=0,ans=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        sum%=mod;
    }
    for(i=0;i<n;i++)
    {
        ans+=(a[i]*(sum-a[i]+mod))%mod;
        ans%=mod;
        sum-=a[i];
        sum=(sum%mod+mod)%mod;
    }
    cout<<ans;
    return 0;
}