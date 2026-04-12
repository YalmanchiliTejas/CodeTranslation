#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
int main()
{
   long int n,i;
   cin>>n;
   
   long int A[n];
   long long pre=0;
   for(i=0;i<n;++i)
   {
       cin>>A[i];
       pre+=A[i];
   }
    
   
   long long ans=0;
   for(i=0;i<n;++i)
   {  
       pre=pre-A[i];
      long long temp=(((pre%1000000007)*(A[i]%1000000007))%1000000007);
      
      ans=(ans%1000000007+temp%1000000007)%1000000007;
   }
   
   cout<<ans<<endl;
   
}