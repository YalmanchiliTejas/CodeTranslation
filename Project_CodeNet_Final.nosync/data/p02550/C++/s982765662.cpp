#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 2e5 + 5;
LL ans , vis[MAXN] , res , num;
LL N , X , M;

int main() {
	scanf("%lld %lld %lld" , &N , &X , &M);
	vis[X] = 1;num = 1;
	LL tmp = X;
	while(1) {
		X = X * X % M;
		num ++;
		if(vis[X]) break;
		vis[X] = num; 
	}
	LL now = 0;
	for (int i = 1; i < vis[X]; ++i) now += tmp , tmp = tmp * tmp % M;
	LL cir = 0 , cur = X , siz = num - vis[X];
	for (int i = 1; i <= siz; ++i) cir += cur , cur = cur * cur % M;
	LL ans = (N - vis[X] + 1) / siz * cir + now;
	N = (N - vis[X] + 1) % siz;
	while(N -- > 0) ans += X , X = X * X % M;
	printf("%lld" , ans);
	return 0;
}