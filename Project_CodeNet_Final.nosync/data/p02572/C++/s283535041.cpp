#include <stdio.h>
#include <iostream>
using namespace std;

long long arr[300000],CS[300000],n;
const int Mod=1e9+7;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
      cin>>arr[i];
      CS[i]=(arr[i]+CS[i-1]);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
      ans=(ans)%Mod+(((CS[n]-CS[i])%Mod)*arr[i])%Mod;
  }
  ans=ans%Mod;
  cout<<ans;
}
