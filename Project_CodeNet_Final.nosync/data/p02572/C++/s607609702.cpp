#include <bits/stdc++.h>
using namespace std;

const long long modConst = 1000000007;
long long A[200005], suffixSum[200005];

int main()
{
	int N;
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
		scanf("%lld", &A[i]);
		
	suffixSum[N + 1] = 0;
	for(int i = N; i >= 1; i--)
		suffixSum[i] = (suffixSum[i + 1] + A[i]) % modConst;
	
	long long ans = 0;
	for(int i = 1; i <= N; i++)
	{
		ans += (A[i] * suffixSum[i + 1]) % modConst;
		ans %= modConst;
	}
	
	printf("%lld", ans);
}
