#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   
   long long int n,mod=1000000007,ans=0;
   cin>>n;
   long long int a[n],i,sum=0;
   for(i=0;i<n;++i)
      { cin>>a[i];
        sum+=a[i];
      }
      
   for(i=0;i<n;++i)
   {
       sum-=a[i];
       ans+=(sum%mod*a[i]%mod)%mod;
   }
   
   cout<<ans%mod;
      
      
   
   
     return 0;
}