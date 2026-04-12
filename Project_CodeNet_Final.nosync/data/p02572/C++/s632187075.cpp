#include<bits/stdc++.h>
#define ll long long int
#define dd double
using namespace std;
const ll MOD = 1000000007;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n;
  cin>>n;
  ll a[n];
  ll i,j;
  ll s=0;
  for(i=0;i<n;i++){
  	cin>>a[i];
  	s=s+a[i];
  }
  
  ll ans=0;
  for(i=0;i<n;i++){
  	s=s-a[i];
  	ans=ans+(s%MOD*a[i]%MOD)%MOD;
  	
  }
  cout<<ans%MOD<<endl;
  
  
  return 0;
}
