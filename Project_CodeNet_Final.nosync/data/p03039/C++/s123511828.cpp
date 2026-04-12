#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int mod = 1000000007;

long long fac[MAX]; //i!%mod=fac[i]
long long finv[MAX]; //pow(i!,-1)%mod=finv[i]
long long inv[MAX]; //pow(i,-1)%mod=inv[i]

// テーブルを作る前処理
void cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(int argc, char const *argv[])
{
	cominit();
	int n,m,k;
	cin>>n>>m>>k;
	long long ans=0LL;
	for (int i = 1; i < n; ++i)
	{
		long long tmp=(long long)i*(n-i)%mod*m%mod*m%mod;
		tmp*=com(n*m-2,k-2);
		tmp%=mod;
		ans+=tmp;
		ans%=mod;
	}
	for (int i = 1; i < m; ++i)
	{
		long long tmp=(long long)i*(m-i)%mod*n%mod*n%mod;
		tmp*=com(n*m-2,k-2);
		tmp%=mod;
		ans+=tmp;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
