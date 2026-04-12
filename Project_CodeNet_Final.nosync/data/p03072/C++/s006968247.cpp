#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define pri 10000000007
using namespace std;
void run(){
	ll n;
	cin>>n;
	ll hi=0,ans=0;
	for(ll i=0;i<n;i++){
		ll h;
		cin>>h;
	   if(h>=hi){hi=h;ans++;}
		
	}
	cout<<ans<<endl;
	
	
	
}
int main() {
	
	ll t=1;
	//cin>>t;
	for(ll i=0;i<t;i++)run();
	
	// your code goes here
	return 0;
}