#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans;
int main(){
	ll N,K; scanf("%lld %lld",&N,&K);
	// ans=N*N;
	for(ll b=1;b<=N;b++){
		ll remain=min(K,b);
		if(!remain) continue;
		ans--;
		ans+=min(N%b+1,remain)*(N/b+1);
		// printf("%lld ",ans);
		remain-=N%b+1;
		if(remain<0) remain=0;
		// printf("%lld ",remain);
		ll t=remain/b;
		ans+=(N/b*t - t*(t+1)/2+t)*b;
		remain%=b;
		ans+=(N/b - t)*remain;
		// printf("%lld\n",ans);
	}
	printf("%lld",N*N-ans);

}