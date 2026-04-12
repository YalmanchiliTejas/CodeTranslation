#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long
#define MOD 998244353

int N, S;
int A[3030];

int main()
{
	scanf("%d %d", &N, &S);
	for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);

	vector<ll> res(S+1), sum(S+1);
	sum[0]++;
	if (A[N] <= S) sum[A[N]]++;
	for(int j=0; j<=S; j++)
	{
		res[j] += sum[j];
		res[j] %= MOD;
	}
	for(int i=N-1; i>=1; i--)
	{
		sum[0]++;
		for(int j=S-A[i]; j>=0; j--)
		{
			sum[j+A[i]] += sum[j];
			sum[j+A[i]] %= MOD;
		}
		for(int j=0; j<=S; j++)
		{
			res[j] += sum[j];
			res[j] %= MOD;
		}
	}
	printf("%lld", res[S]);
	return 0;
}