#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX_N = 3e5;
ll N, M, K;
ll fact[MAX_N], invf[MAX_N];

ll nChoosek(ll n, ll k)
{
	return fact[n]*invf[n-k]%MOD*invf[k]%MOD;
}

ll modpow(ll x, int y)
{
	ll res = 1;
	while(y){
		if(y&1) (res*=x)%=MOD;
		(x *= x)%=MOD;
		y>>=1;
	}
	return res;
}

void solve()
{
	fact[0] = invf[0] = 1;
	for(int i=1;i<MAX_N;++i) fact[i]=(fact[i-1]*i)%MOD;
	invf[MAX_N-1] = modpow(fact[MAX_N-1],MOD-2);
	for(int i=MAX_N-2;i>=1;--i) invf[i]=(invf[i+1]*(i+1))%MOD;
	ll res = 0;
	for(int dx=0; dx<N; ++dx)for(int dy=0;dy<M;++dy){
		ll d = dx + dy;
		ll ways = (N-dx)*(M-dy);
		if(dx && dy) ways *= 2;
		res = (res + d*ways*nChoosek(N*M-2,K-2))%MOD;
	}
	cout << res << '\n';
}

int main()
{
	cin >> N >> M >> K;
	solve();
	return 0;
}