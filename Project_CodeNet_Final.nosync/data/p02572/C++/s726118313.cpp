#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n;
  ll M = 1000000007;
  cin>>n;
  ll A[n];
  ll B[n];
  ll ans = 0;
  for(ll i = 0;i < n;i++)
    cin>>A[i];
  B[n-1] = A[n-1];
  for(ll i = n-2;i >= 0;i--)
  {
    B[i] = (A[i] + B[i+1])%M;
  }
  for(ll i = 0;i < n-1;i++)
  {
    ans = (ans + ((A[i]%M)*(B[i+1]%M))%M)%M;
  }
  cout<<ans<<"\n";
}
  