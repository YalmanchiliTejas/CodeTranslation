#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll sum[200010]={};
	for(ll i=0;i<n;i++){
		sum[i+1]=sum[i]+ch[i];
		sum[i+1]%=inf;
		//cout << sum[i+1]<<endl;
	}
	ll ans=0;
	for(ll i=1;i<n;i++){
		ll now=ch[i]*sum[i];
		now%=inf;
		ans+=now;
		ans%=inf;
	}
	cout <<ans;
	// your code goes here
	return 0;
}