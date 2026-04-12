#include<bits/stdc++.h>
const unsigned int M = 1000000007;
using namespace std;
int main()
{
    
    long long int n,sum=0,ans=0;
    cin>>n;
    long long int a[n],i;
    
    for(i=0;i<n;i++)
    {cin>>a[i]; sum+=a[i];}
    for(i=0;i<n;i++)
    {
      sum-=a[i];
      ans+=((sum%M)*(a[i]%M))%M;
    }
    cout<<ans%M;
}