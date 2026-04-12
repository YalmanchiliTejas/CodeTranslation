// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(k==0)return printf("%lld\n",1ll*n*n),0;
	LL ans=0;
	for(int i=k+1;i<=n;i++){
		ans += 1ll*n/i*(i-k);
//		if(n%i != 0){
		int ni = n-n/i*i;
		ans += ni-k+1>=0?ni-k+1:0;
//		}
//		printf("   %lld %d\n",ans,ni);
	}
	printf("%lld\n",ans);

	return 0;
}
