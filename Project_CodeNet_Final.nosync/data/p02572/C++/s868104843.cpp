#include<iostream>
using namespace std;
int main()
{
  long long int n,sum=0,ans=0,i;
  cin>>n;
  long long int a[n];
  for(i=0;i<n;i++)
  {
    cin>>a[i];
    sum=(sum+a[i]);
  }
  for(i=0;i<n;i++)
  {
      sum=(sum-a[i]);
    ans=(ans+((sum)%1000000007*a[i])%1000000007)%1000000007;
  }
  cout<<ans;
  return 0;
}