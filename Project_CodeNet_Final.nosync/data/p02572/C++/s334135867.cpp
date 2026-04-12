#include<bits/stdc++.h>
#define ll long long int 
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pll pair<ll,ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define mod 1000000007
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define pqmax priority_queue<ll>
using namespace std;
ll power(ll a,ll n){
	if(n==0)
	  return 1;
	if((n%2)==0)
	  return (power((a*a)%mod,n/2))%mod;
	else
	  return (a*(power((a*a)%mod,n/2))%mod)%mod;    
}


int main()
 {
      IOS;
  ll n;
  cin>>n;
  ll a[n];
  ll s[n];
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
  	s[i]=a[i];
  }
  for(int i=n-2;i>=0;i--)
  {
  	s[i]=(s[i]+s[i+1])%mod;
  }
  ll ans=0;
  for(int i=0;i<n-1;i++)
  {
  	ans=(ans+(a[i]*s[i+1])%mod)%mod;
  }
  cout<<ans<<endl;
  
	return 0;
}
