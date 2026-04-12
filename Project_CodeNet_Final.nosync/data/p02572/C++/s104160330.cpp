#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7; 
int main(){
	IOS;
	int n;
	cin>>n;
	vector<ll> u(n);
	for(int i=0;i<n;i++){
		cin>>u[i];
	}
	vector<ll> pref(n);
	pref[0]=u[0];
	for(int i=1;i<n;i++)
	pref[i]=(pref[i-1]+u[i])%mod;
	ll ans=0;
	for(int i=1;i<n;i++){
		ans=(ans+(u[i]*pref[i-1])%mod)%mod;
	}
	cout<<ans;
}