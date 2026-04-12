#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod=1e9+7;
const int mxN=2e5;
ll mode(ll x){
	return ((x%mod+mod)%mod);
}
ll add(ll a,ll b){
	return mode(mode(a)+mode(b));
}
ll mul(ll a,ll b){
	return mode(mode(a)*mode(b));
}

int main(){
//#ifndef ONLINE_JUGDE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
	vector<ll> a(n);
    for(int i=0;i<n;i++)
    	cin>>a[i];
    ll ans=0;
    vector<ll> sum(n+1);
    for(int i=n-1;i>=0;i--){
    	sum[i]=sum[i+1]+a[i];
	}
    for(int i=0;i<n;i++){
    	ans=add(ans,mul(a[i],sum[i+1]));
	}
	cout<<ans;
    return 0;
}