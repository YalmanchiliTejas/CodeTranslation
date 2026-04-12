#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 100;
int N, K; ll ans = 0ll;

void Solve()
{
	scanf("%d%d", &N, &K);
	if(K == 0) { printf("%lld\n", 1ll*N*N); return; }
	for(int i = K+1; i <= N; ++i)
	{
		int a = (i-K) * (N/i), b = N-N/i*i-K+1;
		ans += 1ll * (i-K) * (N/i) + max(0, N-N/i*i-K+1);
	}
	printf("%lld\n", ans);
}

int main()
{
	Solve();
}