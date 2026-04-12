#include<bits/stdc++.h>
using namespace std;
#define m  1000000007
typedef long long ll;

int main()
{
  ll n;
  cin>>n;
  ll i,j,sum=0,x=0;
  ll a[n];
  for(ll i;i<n;i++)
  {
    cin>>a[i];
    sum=sum+a[i];
   
  }
  for(ll i=0;i<n-1;i++)
  {
    sum=sum-a[i];
    x=x + sum%m*a[i]%m;
      x=x%m;
}
  cout<<x;
}
