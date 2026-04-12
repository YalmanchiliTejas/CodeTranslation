#include <bits/stdc++.h>
#define ll long long int
#define ulli unsigned long long int 
#define pb push_back
using namespace std;
ll BS(ll s[],ll q,ll n)
{
    ll beg = 0,last = n;
    while(beg<=last)
    {
        ll mid = (beg+last)/2;
        if (s[mid+1]>=q && s[mid]<q)
            return mid+1;
        else if (s[mid]<q)
            beg = mid+1;
        else 
            last = mid-1;
    }
    return 0;
}
bool isprime(ll n) 
{
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
} 
int main()
{  
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   //while(!cin.eof())
   int t; t=1;
   ll mod=1000000007;
   while(t--)
   {
       ll n;
       cin>>n;
       ll a[n],s[n],ans=0;
       
       for(ll i=0;i<n;i++) cin>>a[i];
       s[n-1]=a[n-1];
        for(ll i=n-2;i>=0;i--)
              s[i]=(a[i]+s[i+1] )%mod;
        
        for(ll i=0;i<n-1;i++)
            ans=( ans%mod + (a[i]%mod) * (s[i+1]%mod)%mod)%mod;
       cout<<ans;
   }
   return 0;
}