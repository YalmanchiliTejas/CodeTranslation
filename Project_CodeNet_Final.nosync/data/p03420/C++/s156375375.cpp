#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	for(ll i=k+1;i<=n;i++){
		ans+=n/i*(i-k);
		if(k==0){
			ans+=max(n%i-(k),ll(0));
		}
		else{
			ans+=max(n%i-(k-1),ll(0));
		}
	//	cout <<ans<<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}