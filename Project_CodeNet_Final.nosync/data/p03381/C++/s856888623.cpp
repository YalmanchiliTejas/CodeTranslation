#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair

using namespace std;
typedef long long ll;
ll mod = 998244353;
int main() {
	fastio;
	ll n;
	cin>>n;
	vector<ll> a(n,0),b;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	b = a;
	sort(b.begin(),b.end());
	
	ll ind1 = n/2-1, ind2 = n/2;
	for(ll i=0;i<n;i++){
		if(a[i]<=b[ind1]){
			cout<<b[ind2]<<"\n";
		}
		else{
			cout<<b[ind1]<<"\n";
		}
	}
	
	
	
	
}




