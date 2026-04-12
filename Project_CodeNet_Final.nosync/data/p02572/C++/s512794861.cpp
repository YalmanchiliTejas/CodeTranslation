#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define f(i,n) for(int i=0;i<n;i++) 
#define F first 
#define S second 
#define pb push_back 

using namespace std;

ll mod = 1e9 + 7;

void test(){
	ll n;
	cin>>n;
	ll a[n];
	f(i,n)cin>>a[i];
	ll suf[n];
	suf[n-1] = 0;
	for(int i=n-2;i>=0;i--){
		suf[i] = (suf[i+1] + a[i+1])%mod;
	}
	ll ans = 0;
	f(i,n){
		ans = ans + (a[i]*suf[i])%mod;
	}
	ans = ans%mod;
	cout<<ans<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
