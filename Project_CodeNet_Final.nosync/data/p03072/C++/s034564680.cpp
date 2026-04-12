#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define all(v)  v.begin(),v.end()
#define pb push_back
#define size(v)  (int) v.size()
#define fast ios_base:: sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
ll power_mod(ll a,ll x){if(x==0) return 1;ll y=power_mod(a,x/2);ll ans=(y*y)%mod; if(x%2) ans=(ans*a)%mod;return ans;}
ll inv(ll a){return power_mod(a,mod-2);}
ll power(ll a, ll x){ if(x==0) return 1; ll y= power(a,x/2); ll ans=(y*y); if(x%2) ans*=a; return ans;}




int main()
{
   

   int n;
   cin>>n;
   int a[n+1];
   for(int i=1;i<=n;i++) cin>>a[i];
    int ct=0,mx=0;
   for(int i=1;i<=n;i++)
   {  
       if(a[i]>=mx)
       {
          mx=a[i];
          ct++;
       }
   }

   cout<<ct<<endl;
}


