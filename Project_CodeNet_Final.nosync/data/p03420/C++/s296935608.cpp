#include <algorithm>
#include   <cstring>
#include    <cstdio>
using namespace std;

typedef long long LL;
int n,K;
LL ans;

int main(){
	scanf("%d%d",&n,&K);
	if(K==0){
		printf("%lld\n",1LL*n*n);
		return 0;
	}
	for(int i=K+1;i<=n;i++){//this is b
		int cnt=n/i;
		int r=n%i;
		ans+=1LL*cnt*(i-1-K+1);
		if(r>=K)
			ans+=r-K+1;
	}
	printf("%lld\n",ans);
	return 0;
}