#include <cstdio>
#include <iostream>
using namespace std;

int N, K;
long long res;

void solve()
{
	int i=K+1, j;
	if(K==0){
		res = 1ll*N*N;
		printf("%lld\n", res);
		return ;
	}
	if(i==0)
		i = 1;
	for(; i<=N; i++){
		j = N/i;
		/*if(i*j+K > N)
			j --;
		res += j*(i-K);
		res += N-i*j-K+1;*/
		res += 1ll*(j+1)*(i-K);
		res -= 1ll*i*j+(i-1) - max(N, i*j+K-1);
		//res -= (i*j+K-N);
	}
	printf("%lld\n", res);
}

int main()
{
	scanf("%d%d", &N, &K);
	solve();
	return 0;
}