#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define deb(x) cout<<#x<<" "<<x<<endl;

using namespace std;
ll power(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   		  res%=mod;
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2
        x%=mod; 
    } 
    return res%mod; 
}	
void run(){
	ll n,m;
	cin>>n;
	ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
	ll s1=0;
	ll s2=0;
	for(ll i=0;i<n;i++){
		s1+=a[i];
		s2+=(a[i]*a[i]);
		s1%=mod;
		s2%=mod;
	}
	s1=(s1*s1)%mod;
	s1=(s1-s2+mod)%mod;
	ll z=power(2,mod-2);
	s1=s1*z;
	s1%=mod;
	cout<<s1<<endl;
	
	
}

int main() {
	int t=1;
	//cin>>t;
	for(ll i=0;i<t;i++){
	run();
	}
	// your code goes here
	return 0;
}