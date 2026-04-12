#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,k;

int main(void){
	scanf("%d%d",&n,&k);
	ll ans=0;
	for(int i=k+1;i<=n;i++){
		int s=k;
		int lo=(n-k)/i;
		int ga=lo*i+k;
		ans+=(ll)min(i-k,n-ga+1);
		ans+=(ll)lo*(i-k);
		//printf("%lld\n",ans);
	}
	if(k==0LL)ans-=n;
	printf("%lld\n",ans);
	return 0;
}