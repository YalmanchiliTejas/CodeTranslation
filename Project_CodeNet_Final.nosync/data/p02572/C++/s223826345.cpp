#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long
#define MOD 1000000007
#define inv2 500000004

int N;
ll A[200201];

int main()
{
	scanf("%d", &N);
	ll sum = 0, res = 0;
	for(int i=1; i<=N; i++)
	{
		scanf("%lld", &A[i]);
		sum += A[i];
	}
	sum %= MOD;
	res += sum*sum; res %= MOD;

	for(int i=1; i<=N; i++)
		res -= A[i]*A[i]%MOD;
	res %= MOD;

	res *= inv2; res %= MOD;
	
	res %= MOD; res += MOD; res %= MOD;
	printf("%lld", res);
	return 0;
}