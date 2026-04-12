#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  long long mod=1e9+7;
  long long arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  long long suffix[n];
  suffix[n-1]=arr[n-1]%mod;
  for(int i=n-2;i>0;i--)
    suffix[i]=(suffix[i+1]+arr[i])%mod;
  long long ans=0;
  for(int i=0;i<n-1;i++)
    ans=(ans+(arr[i]*suffix[i+1])%mod)%mod;
  cout<<ans<<endl;
  return 0;
}