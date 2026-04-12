#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int M=1e9+7;

long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n; cin>>n;
	ll arr[n], arr1[n];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
		arr1[i]=arr[i];
	}
	
	for(ll i=n-2; i>=0; i--){
		arr[i]+=arr[i+1];
	}
	
	ll ans = 0;
	for(int i=n-2;i>=0; i--){
        ans=add(ans,mul(arr1[i],arr[i+1]));
    }
	
	cout<<ans<<"\n";
	
	return 0;
}