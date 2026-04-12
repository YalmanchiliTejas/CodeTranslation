#include <cstdio>
using namespace std;
long long N;
long long X, M;
long long ans;
bool ud[100010];
long long ls[100010];
int lp, lsu;
int main()
{
	scanf("%lld %lld %lld", &N, &X, &M);
	ud[X] = true;
	ls[1] = X; 
	for (int i = 2; i <= 100010; i++)
	{
		X = X*X%M;
		if (ud[X])
		{
			lp = X;
			lsu = i-1;
			break;
		}
		else
		{
			ud[X] = true;
			ls[i] = X;
		}
	}
	if (N <= lsu)
	{
		for (int i = 1; i <= N; i++)
		{
			ans += ls[i];
		}
	}
	else
	{
		int i;
		for (i = 1; i <= lsu; i++)
		{
			if (ls[i] != lp)
			{
				ans += ls[i];
			}
			else
			{
				break;
			}
		}
		long long sm = 0;
		for (int j = i; j <= lsu; j++)
		{
			sm += ls[j];
		}
		ans += ((N-(i-1)) / (lsu-i+1)) * sm;
		int rs;
		rs = (N-(i-1)) % (lsu-i+1);
		for (int j = 0; j < rs; j++)
		{
			ans += ls[i+j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}