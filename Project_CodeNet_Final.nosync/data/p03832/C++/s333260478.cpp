#include<iostream>
#include<cstring>
#define N 1000
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL mod_pow(LL base, LL exp)
{
	if(exp==0) return 1;
	if(exp&1) return (base*mod_pow(base,exp-1))%MOD;
	else return mod_pow((base*base)%MOD,exp/2);
}
LL inv(LL n){ return mod_pow(n,MOD-2); }
LL fac[N+1];
LL fac_inv[N+1];
LL C(LL n, LL k)
{
	if(k < 0 || k > n) return 0;
	LL num = fac[n];
	LL den = (fac_inv[k]*fac_inv[n-k])%MOD;
	return (num*den)%MOD;
}
LL cost[N+1][N+1];
LL memo[N+1][N+1];
LL A, B, C2, D;
LL dp(LL n, LL sz)
{
	if(n==0) return 1;
	if(n < 0 || sz > B) return 0;
	if(memo[n][sz]!=-1) return memo[n][sz];

	LL ans = dp(n,sz+1); //count = 0
	for(LL count = C2; count <= D && sz*count <= n; count++)
	{
		LL x1 = C(n,sz*count)*cost[count][sz]%MOD;
		   x1 = (x1*dp(n-sz*count,sz+1))%MOD;
		ans = (ans+x1)%MOD;
	}
	return memo[n][sz] = ans;
}
int main()
{
	fac[0] = 1;
	for(LL n = 1; n <= N; n++)
		fac[n] = (fac[n-1]*n)%MOD;
	fac_inv[N] = inv(fac[N]);
	for(LL n = N-1; n >= 0; n--)
		fac_inv[n] = (fac_inv[n+1]*(n+1))%MOD;

	for(LL count = 1; count <= N; count++)
		for(LL sz = 1; sz <= N; sz++)
			if(count*sz <= N)
			{
				LL x1 = (fac[sz*count]*fac_inv[count])%MOD;
				cost[count][sz] = (x1*mod_pow(fac_inv[sz],count))%MOD;
			}

	int n; cin >> n;
	cin >> A >> B >> C2 >> D;

	memset(memo,-1,sizeof memo);
	cout<<dp(n,A)<<endl;

	return 0;
}