#include<bits/stdc++.h>
#pragma GCC optimize ("-O3")
    using namespace std;
    #define ll long long
    #define ld long double
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define pll pair<ll,ll>
    #define ff first
    #define ss second
    #define pb push_back
    #define deb(x) cout<<#x<<" : "<<x<<endl;
    #define deb2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
    #define deb3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
    #define deb4(w,x,y,z) cout<<#w<<" : "<<w<<"\t"<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
    #define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define printv(a)  for(ll i=0;i<a.size();i++)  cout<<a[i]<<" ";
   
   
    const int mod=1e9+7;
    const int N=1e6+5; 
   
    bool sortbysec(const pair<pair<ll,ll>,ll> &a, 
                      const pair<pair<ll,ll>,ll> &b) 
        { 
            return (a.second > b.second); 
        } 
        ll powermod(ll x, ll y, ll p)
        {
            ll res = 1;
            x = x % p;
            while (y > 0)
            {
                if (y & 1) res = (res*x) % p;
                y = y>>1;
                x = (x*x) % p;
            }
            return res;
        }
       
        bool isprime(int n) 
        { 
            if (n <= 1)  return false; 
            if (n <= 3)  return true; 
            if (n%2 == 0 || n%3 == 0) return false; 
            for (int i=5; i*i<=n; i=i+6) 
                if (n%i == 0 || n%(i+2) == 0) 
                   return false; 
           return true; 
        }
       
        
     
        int main()
    {
        FAST;
       ll n;
       cin>>n;
       vll a(n);
       for(ll i=0;i<n;i++)
       cin>>a[i];
       ll dp[n+1][n+1]={0};
       for(ll L=n-1;L>=0;L--)
       {
          for(ll R=L;R<n;R++)
          {
              dp[L][R]=max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
          }
       }
       cout<<dp[0][n-1];
        return 0;
    }