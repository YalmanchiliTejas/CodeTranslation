#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
 
int32_t main()
{
  int n;cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<int>right(n,0);
  for(int i=n-2;i>=0;i--)
  {
    right[i]=(right[i+1]+arr[i+1])%mod;
  }
  int ans=0;
  for(int i=0;i<n-1;i++)
  {
    ans=(ans+(arr[i]*right[i]))%mod;
  }
  cout<<ans%mod<<endl;
}