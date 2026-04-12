#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;
long long mod = pow(10,9)+7;
int main()
{
  int n;
  cin>>n;
  
  ll arr[n];
  ll sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    sum-=arr[i];
    ans+=((sum%mod)*(arr[i]%mod))%mod;
  }
  ans%=mod;
  cout<<ans;
}
  