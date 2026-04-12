#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long s1=0,s=0,n,i,j,x,y,m=1000000007,ans=0;
   cin>>n;
   long long a[n+3];
   
   for(i=0;i<n;i++) 
   {
    cin>>a[i];
    s+=a[i];
   }
   for(i=0;i<n;i++)
   {
    s1+=a[i];
    x=s-s1;
    y=((a[i]%m)*(x%m))%m;
    ans=((ans%m)+(y%m))%m;
   }
   cout<<ans<<endl;
}