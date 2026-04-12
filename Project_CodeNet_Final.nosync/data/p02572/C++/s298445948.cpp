#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,x;
  cin>>n;
  ll sum1=0,sum2=0;
  for(ll i=0; i<n; i++){
        cin>>x;
    sum1=(sum1+sum2*x)%mod;
    sum2=(sum2+x)%mod;
  }
  cout<<(sum1)%mod;



    return 0;
}