#include<iostream>
using namespace std;
#define ll long long int
int main()
{ 
  ll n;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  ll sum=0;
  ll mod=1e9+7;
 
  
  for(int i=n-2;i>=0;i--)
  {
      sum=sum+a[i]*a[i+1];
      sum=sum%mod;
      a[i]=a[i]+a[i+1];
      a[i]=a[i]%mod;
  }
  cout<<sum;
  
}
