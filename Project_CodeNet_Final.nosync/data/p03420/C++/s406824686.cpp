#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,k,ans=0;
	scanf("%lld %lld",&n,&k);
	for(ll b=k+1;b<=n;++b) ans+=(((b-k)*(n/b))+max(0ll,n+1-(b*(n/b)+k)));
	if(k==0) printf("%lld\n",ans-(n-k));
	else printf("%lld\n",ans);
}