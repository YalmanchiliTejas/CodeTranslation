#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n;
  cin>>n;
  unsigned long long int a[n],pre[n],s=0,ans=0;
  for(long long int i=0;i<n;i++)
  {
  cin>>a[i];
  s+=a[i];
  }
  for(long long int i=0;i<n;i++)
  {
    s=s-a[i];
    pre[i]=s%1000000007;
  }
  for(long long int i=0;i<n;i++)
  {
    ans+=(a[i]*(pre[i]))%1000000007;
  }
  cout<<ans%1000000007<<endl;
}