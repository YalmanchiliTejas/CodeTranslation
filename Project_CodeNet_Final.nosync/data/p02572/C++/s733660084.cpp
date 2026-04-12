#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define MOD 1000000007
int main(){
	ll a, cnt=0, ans=0;
	cin>>a;
	ll arr[a];
	for (ll i=0; i<a; i++) cin>>arr[i], cnt+=arr[i];
	for (ll i=0; i<a-1; i++){
		cnt-=arr[i];
		ans+=(arr[i]%MOD)*(cnt%MOD);
		ans%=MOD;
	}
	cout<<ans<<endl;
}
//    ll a, ans=0;
//    cin>>a;
//    ll arr[a+1], ps[a+1];
//    for (ll i=1; i<=a; i++) cin>>arr[i];
//    ps[0]=0;
//    for (ll i=1; i<=a; i++) ps[i]=ps[i-1]+arr[i];
//    for (ll i=1; i<a; i++){
//        ans+=(arr[i]*((ps[a]-ps[i])%MOD))%MOD;
//        ans%=MOD;
//    }
//    cout<<ans<<endl;
