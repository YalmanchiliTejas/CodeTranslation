#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
	int n,k;cin>>n>>k;
	ll ans=0;
	for(int i=k+1;i<=n;i++){
		ll a=(n-k)%i+1;
		ll b=i-k;
		a=min(a,b);
		ll c=(n-k)/i+1;
		ans+=c*a+(c-1)*(b-a);
		if(k==0)ans--;
	}
	cout<<ans<<endl;
}