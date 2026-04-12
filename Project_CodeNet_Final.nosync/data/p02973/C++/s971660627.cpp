#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n;
	cin >> n;
	vector<ll> A(n+1, 1e9);
	for(ll i=0;i<n;i++){
		ll x;
		cin >> x;
		*upper_bound(A.begin(), A.end(), -x) = -x;	
	}
	for(ll i=0;i<=n;i++) if(A[i]==1e9) { cout<<i<<"\n"; break; }
	
}