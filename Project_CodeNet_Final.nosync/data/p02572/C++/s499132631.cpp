#include<bits/stdc++.h>
#define ll long long

using namespace std;



int main()
{ 
int n;
  cin>>n;
  ll a[n],pref[n];
  for(int i=0;i<n;i++) cin>>a[i];
  pref[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--)
    pref[i]=a[i]+pref[i+1];
  
  ll ans=0;
  for(int i=0;i<n-1;i++)
  {    ans=(ans+(a[i]%1000000007)*(pref[i+1]%1000000007)%1000000007)%1000000007;
  }
  cout<<ans;
 
 
}