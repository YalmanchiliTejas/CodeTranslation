#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define mod 1000000007

ll power (ll a, ll r)
{
	if (r==1) return a;
	else
	{
		ll m;
		m=power(a,r/2);
		if (r%2==0) return m*m%mod;
		else return m*m%mod*a%mod;
	}
}

ll modinv(ll a)
{
	return power(a,mod-2);
}

ll cmb(ll n,ll r)
{
	ll ans=1;
	for (int i=0;i<r;i++)
	{
		ans=(ans*(n-i)%mod*modinv(i+1))%mod;
	}
	return ans;
}

int main()
{
	ll N,M,K; cin >> N>> M >> K;
	ll ans=0;
	for (int m=2;m<M+1;m++)
	{
		ans=(ans+(m-1)*(M-m+1)%mod*N*N%mod)%mod;
	}
	for (int n=2;n<N+1;n++)
	{
		ans=(ans+(n-1)*(N-n+1)%mod*M*M%mod)%mod;
	}
	cout << ans*cmb(N*M-2,K-2)%mod << endl;
	return 0;
}