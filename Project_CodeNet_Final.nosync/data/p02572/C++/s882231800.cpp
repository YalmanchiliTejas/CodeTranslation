#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<utility>
#include<climits>
#include<set>
using namespace std;
#define ll long long


int main(){ 
	ios_base::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	    
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif

	ll n;cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	ll ans=0;
	int modul=1'000'000'007;
	ll sum=0;
	ll x=0;

	for(int i=0;i<n;i++)
	{
		ans=(ans + v[i]*x)%modul;
		x=(x + v[i])%modul;
	}
	cout<<ans%modul;
    
}