#include<bits/stdc++.h>

#define HAS_TEST_CASE 0

namespace rG{

typedef long long ll;

const int N=5e5;
const ll P=1e9+7;

int n,m,k;
ll a[N+10];
char s[N+10];
ll sum[N+10],ans;

inline void main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
		sum[i]=(sum[i-1]+a[i])%P;
	for(int i=1;i<=n;i++)
		(ans+=1LL*a[i]*(((sum[n]-sum[i])%P+P)%P)%P)%=P;
	printf("%lld\n",ans);
}

} // namespace rG

int main(){
#if defined(LOCAL)&&HAS_TEST_CASE
	freopen("tmp.out","w",stdout);
#endif
#if HAS_TEST_CASE
	int T;
	scanf("%d",&T);
	while(T--)rG::main();
#else
	rG::main();
#endif
	return 0;
}
