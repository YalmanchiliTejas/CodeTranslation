#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, a[N];
LL sum[N];
int main(){
	scanf ("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		scanf ("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i]; sum[i] %= mod;
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	ans = (ans + sum[i - 1] * a[i] % mod) % mod;
	printf ("%lld\n", ans);
  return 0;
}