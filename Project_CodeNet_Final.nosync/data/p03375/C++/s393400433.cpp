#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100005
#define PLI pair<long long,int>
#define fi first
#define se second
#define mp make_pair
//#define ivorysi
using namespace std;
typedef long long int64;
int N,M;
int64 C[3005][3005],S[3005][3005],ans;

int64 fpow(int64 x,int64 c,int64 MOD) {
	int64 res = 1,t = x;
	while(c) {
		if(c & 1) res = res * t % MOD;
		t = t * t % MOD;
		c >>= 1;
	}
	return res;
}
int64 ways(int x) {
	int64 res = 0;
	int64 tmp2 = fpow(2,fpow(2,N - x,M - 1),M);
	int64 t = fpow(2,N - x,M);
	int64 tmp1 = 1;
	for(int j = 0 ; j <= x ; ++j) {
		res += S[x][j] * tmp1 % M * tmp2 % M;
		tmp1 = tmp1 * t % M;
		res %= M;
	}
	return res;
}
void Solve() {
	scanf("%d%d",&N,&M);
	C[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i) {
		C[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
		}
	}
	S[0][0] = 1;S[1][1] = 1;
	for(int i = 1 ; i <= N ; ++i) {
		S[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j) {
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * (j + 1)% M) % M;
		}
	}
	int t = 1;
	for(int i = 0 ; i <= N ; ++i) {
		(ans += t * C[N][i] % M * ways(i) % M) %= M;
		t = 1LL * t * (M - 1) % M;
	}
	printf("%lld\n",ans);
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Solve();
	return 0;
}