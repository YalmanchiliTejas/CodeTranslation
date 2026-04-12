#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NMAX = 2e5 + 10;
const int MOD = 1e9 + 7;
ll loc[NMAX] ;
ll pre_sum[NMAX];
int main(int argc, char const *argv[])
{
	ll n , ans = 0;
	ll x , m ,pos = 1;
	scanf("%lld%lld%lld",&n,&x,&m);
	loc[x] = 1;
	pre_sum[1] = x % m;
	for(register ll i = 2;i <= n && !loc[x*x%m];i++)
	{
		x = x*x%m;
		loc[x] = i;
		pre_sum[i] = pre_sum[i - 1] + x;
		pos = i;
	}
	if(pos == n)
		return 0*printf("%lld\n",pre_sum[n]);
	ans += pre_sum[loc[x*x%m] - 1];
	ll T = pos - loc[x*x%m] + 1;
	ans += (pre_sum[pos] - pre_sum[loc[x*x%m] - 1]) * ((n - loc[x*x%m] + 1)/T);
	ans += pre_sum[loc[x*x%m] - 1 + (n - loc[x*x%m] + 1)%T] - pre_sum[loc[x*x%m] - 1];
	printf("%lld\n",ans );
	return 0;
}
