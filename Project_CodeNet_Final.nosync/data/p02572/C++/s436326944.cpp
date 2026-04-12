#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
const LL mod = 1e9 + 7;
LL a[N];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	LL sum = 0;
	LL ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans + sum * a[i] % mod) % mod;
		sum = (sum + a[i]) % mod;
	}
	cout<<ans<<endl;
	return 0;
}