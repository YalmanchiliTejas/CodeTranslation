#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define pri 1000000007
#define all(x) x.begin(),x.end()
#define mx 32
using namespace std;

void masterstroke(){
	ll n;
	cin>>n;
	ll a[n];
	multiset <ll> e;
	for(ll i=0;i<n;i++){
	cin>>a[i];
	if(e.size()==0){e.insert(a[i]);}
	else{
	     auto  f=e.lower_bound(a[i]);
	     if(f==e.begin()){e.insert(a[i]);}
		 else{
		      f--; 
	          e.erase(f);
		      e.insert(a[i]);
		   }
	}
	
	}
	cout<<e.size();
	
	
    

}


int main() {
	ll t=1;
	//cin>>t;
	for(ll i=0;i<t;i++)masterstroke();
	
	// your code goes here
	return 0;
}
