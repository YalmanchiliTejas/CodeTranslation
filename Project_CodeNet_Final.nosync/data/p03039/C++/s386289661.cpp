#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n, m, k;
const ll mod = 1e9 + 7;
ll mypow(ll a, ll b) {
	if (b == 0)return 1;
	if (b % 2)
		return (a*mypow((a*a) % mod, b / 2)) % mod;
	else
		return mypow((a*a) % mod, b / 2);
}
ll fac[200010];
ll rev[200010];
ll mul(ll a, ll b) {
	return (a*b) % mod;
}
ll sub(ll a, ll b) {
	return (a - b + mod) % mod;
}
ll sum(ll a, ll b) {
	return (a + b) % mod;
}
ll Comb(ll a, ll b) {
	return mul(rev[a - b], mul(fac[a], rev[b]));
}
int main()
{
	rev[0] = 1;
	fac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		rev[i] = mypow(fac[i], mod - 2);
	}
	scanf("%lld %lld %lld", &n, &m, &k);
	ll dap = 0;
	for (ll i = 2; i <= n; i++) {
	
		dap = sum(dap, sub(mul(mul(i - 1, m), mul(m, i)),mul(mul(mul(i, i - 1), rev[2]), mul(m,m))));
	}
	for (ll i = 2; i <= m; i++) {
		dap = sum(dap, sub(mul(mul(i - 1, n), mul(n, i)), mul(mul(mul(i, i - 1), rev[2]), mul(n,n))));
	}
	dap = mul(dap, Comb(n*m - 2, k - 2));
	printf("%lld", dap);
}
