#include<iostream>
using namespace std;
int main (void)
{
  int i,j,k,n,MOD=1000000007;
  long long int a[200000],sum,ans,c;
  
  cin>>n;
  for(i=0;i<n;i++){cin>>a[i];}
  ans=0;sum=0;
  
  for(i=0;i<n;i++){sum+=a[i];}
  
  for(i=0;i<n;i++)
  {
    sum=sum-a[i];
    c=sum%MOD;
    a[i]=a[i]%MOD;
    ans=ans+a[i]*c;
    ans=ans%MOD;
    
  }
  cout<<ans<<endl;
  return 0;
}