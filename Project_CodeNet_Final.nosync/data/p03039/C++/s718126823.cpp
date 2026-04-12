#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define pri 1000000007 
using namespace std;
ll power(ll x,ll y,ll p) 
		{   ll res = 1; 
		    x = x % p;    
		    while (y > 0) 
		    { 
		            if (y & 1) 
		            res = (res*x) % p; 
		        y = y>>1; // y = y/2 
		        x = (x*x) % p;   
		    } 
		    return res; 
		} 
ll nCr(ll n, ll r, ll p) 
		{  ll ze=1;
		    if(r>n)return 0;
		   for(ll i=n-r+1;i<=n;i++){
		   	ze=(ze*i)%pri;
		   	
		   }
		   for(ll j=2;j<=r;j++){
		   	ze=(ze*power(j,pri-2,pri))%pri;
		   }
		   return ze;
		} 
		 
int main() {
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans=nCr(n*m-2,k-2,pri);
	ll  ans1=(ans*m)%pri;
	  ans1=(ans1*m)%pri;
	  ans1=(ans1*n)%pri;
	  ans1=(ans1*(n+1))%pri;
	  ans1=(ans1*(n-1))%pri;
	ll  ans2=(ans*n)%pri;
	  ans2=(ans2*n)%pri;
	  ans2=(ans2*m)%pri;
	  ans2=(ans2*(m+1))%pri;
	  ans2=(ans2*(m-1))%pri;
ll z= power(6,pri-2,pri);
ans1=(ans1*z)%pri;
ans2=(ans2*z)%pri;
cout<<(ans1+ans2)%pri<<endl;

	// your code goes here
	return 0;
}