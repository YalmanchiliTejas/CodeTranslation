#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t n,ans,sum;
  sum=0;
  ans=0;
  cin>>n;
  vector<int64_t> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    sum+=a.at(i);
  }
  for(int i=0;i<n-1;i++)
  {
    sum-=a.at(i);
    ans+=a.at(i)*(sum%1000000007);
    ans=ans%1000000007;
  }
  cout<<ans<<endl;
}