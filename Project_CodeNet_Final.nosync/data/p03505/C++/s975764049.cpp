#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	long long k, x, y, ans;

	scanf("%lld %lld %lld", &k,&x,&y);
	if (x >= k)ans = 1;
	else if (x > y){
		ans = (k - x - 1) / (x - y);
		ans = ans * 2 + 3;
	}

	if (x<=y&&x<k)printf("-1\n");
	else printf("%lld\n",ans);

	return 0;
}