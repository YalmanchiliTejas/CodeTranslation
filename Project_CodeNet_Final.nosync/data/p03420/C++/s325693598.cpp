#include<bits/stdc++.h>
#ifdef WIN32
#define ld "%I64d"
#else
#define ld "%lld"
#endif
using namespace std;
int main(){
	int n,k,i,j,l;
	scanf("%d%d",&n,&k);
	if(!k){
		printf(ld,1ll * n * n);
		return 0;
	}
	long long ans = 0;
	for(i = 1;i <= n;++i){
		if(i < k) continue;
		j = n / i  * i;
		l = n - j;
		if(l >= k) ans += l - k + 1;
		ans += j - n / i * k;
	}
	printf(ld,ans);
	return 0;
}