#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	for(ll b=1;b<=n;b++){
		ll p=n/b;
		ll zero=0;
		ll pko=max(zero,b-k);
		ans+=p*pko;
		ll s=b*(p)+k;
		ans+=max(zero,n-s+1);
	}
	if(k==0){
		ans=ans-n;
	}
	cout <<ans;
	return 0;
}