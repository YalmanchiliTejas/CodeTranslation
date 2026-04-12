#include <cstdio>
#define ll long long int
#define MOD 1000000007
ll N, A[200005], sum[200005], ans;
ll SUM(int i, int j)
{
	return (sum[j]-sum[i-1])%MOD;    //此时 sum[j]-sum[i-1] 是正数 
}
int main()
{
	scanf("%lld", &N);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld", &A[i]);
		sum[i] = sum[i-1]+A[i];     //sum 不取模 
	}
	for(int i=1;i<N;i++)
		ans = (ans+(A[i]*SUM(i+1, N))%MOD)%MOD;
	printf("%lld\n", ans);
	return 0;
}