#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
	cin>>n>>k;
	ll ans=0;
	for (ll b=n;b>k;b--){
		ll l=k,r=b-1;
		ll c=(n+1)/b;
		ans+=c*(r-l+1);
		if (l==0) ans--;
		l=k+c*b;
		if (l<=n){
			ans+=n-l+1;
		}
	}

	cout<<ans;
}