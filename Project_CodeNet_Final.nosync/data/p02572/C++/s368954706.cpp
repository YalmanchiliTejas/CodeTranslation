#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main()
{
  int n;
  ll sum,pro,ans;

  cin>>n;
  vector<ll>arr(n),arans(n);
  sum=0;ans=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
    arans[i]=sum;
  }
  for(int i=0;i<n;i++){
    pro = (arr[i]*((arans[n-1]-arans[i])%mod))%mod;
    ans+=pro;
    ans = ans%mod;
  }
  cout<<ans<<endl;


    return 0;
}


