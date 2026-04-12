#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=1e9 +7;
#define vi vector<int>
#define pb emplace_back
ll poww(ll n,ll x)
{
    ll res=1;
    
    while(x>0)
    {
        if(x&1)
          res*=n;
        
        x=x>>1;
        n*=n;
    }
    return res;
}





int main() 
{
	   ios::sync_with_stdio(0);
	   cin.tie(0);
	   cout.tie(0);
       
       ll n;
       cin>>n;
       ll *a= new ll[n];
       for(int i=0;i<n;i++)
        cin>>a[i];
       
       ll *pref= new ll[n+1];
       pref[n+1]=0;
       for(int i=n-1;i>=0;i--)
       {
       	pref[i]=(pref[i+1] + a[i])%mod;
       } 
       ll sum=0;
       for(int i=0;i<n;i++)
         {
             sum+= (a[i]*pref[i+1])%mod;
         }
         cout<<sum%mod;
       
}