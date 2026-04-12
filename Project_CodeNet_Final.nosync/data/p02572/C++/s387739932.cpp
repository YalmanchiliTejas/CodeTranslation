#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 200005;
 
const ll MOD = 1e9+7;
ll a[N];
ll sum[N];
ll powermod(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b&1){
			ret *= a;
			ret %= MOD;
		}
		b >>= 1;
		a *= a;
		a %= MOD;
	}
	return ret;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=n;i>0;i--){
		sum[i] = sum[i+1] + a[i+1];
		sum[i] %= MOD;
	}
	
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans += (sum[i] * a[i])%MOD;
		ans %= MOD;
	}
	cout<<ans;
	
	
	return 0;
}
