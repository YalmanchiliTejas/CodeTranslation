#include<iostream>
#include<cstdio>
using namespace std;
const int SIZE = 200000 + 10, mod = 1000000007;
const int p = 500000004;
long long n, A[SIZE], s, t, ans;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) scanf("%lld", &A[i]);
	s = t = 0;
	for(int i = 0; i < n; ++ i)
	{
		s = (s + A[i]) % mod;
		t = (t + A[i] * A[i]) % mod;
	}
	s = s * s % mod;
	ans = (s - t + mod) % mod;
	printf("%d\n", (long long)(ans * p) % mod);
	return 0;
}