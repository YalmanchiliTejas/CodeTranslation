#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=3e5+1;
const ll INF=1e10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(ll &i:a) cin>>i;
	ll sum=0,ans=0;
	for(int i=0;i<n;i++){
		ans=(ans+sum*a[i])%mod;
		sum=(sum+a[i])%mod;
	}
	cout<<ans;
} 
