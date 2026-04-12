#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll A[52];
int main()
{
	scanf("%lld",&N);
	for(ll i=0;i<N;i++){
		scanf("%lld",&A[(int)i]);
	}
	ll l=-1,r=(ll)(1000000000000000000);
//	printf("%lld\n",r-l);
	while(r-l>1){
		ll c=(l+r)/2LL;
		ll cou=0LL;
		for(ll i=0LL;i<N;i++){
			cou+=max(0LL,(A[(int)i]+c+1)/(N+1LL));
		}
		//printf("c=%lld:cou=%lld\n",c,cou);
		if(cou<=c){
			r=c;
		}
		else{
			l=c;
		}
	}
	//printf("%lld\n",r);
	ll ans=max(0LL,r-(N-1LL)*N);
	while(true){
		ll c=ans;
		ll cou=0LL;
		for(ll i=0LL;i<N;i++){
			cou+=max(0LL,(A[(int)i]+c+1)/(N+1LL));
		}
		if(cou<=c){
			break;
		}
		else{
			ans++;
		}
		
	}
	printf("%lld\n",ans);
	return 0;
}
