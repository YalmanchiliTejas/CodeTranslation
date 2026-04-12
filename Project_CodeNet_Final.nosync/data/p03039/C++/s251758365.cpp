#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()
 
#define cMOD 1000000007ULL
#define cINF ((1ull<<62)-1)
#define cINFINT ((1<<30)-1)


ll combinationValue( ll n, ll k, ll mod )
{
	vector<ll> fac( n+1, 1 ), inv( n+1, 1 ), facInv( n+1, 1 );
	for( ll i = 2; i <= n; ++i )
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * ( mod / i ) % mod; // 逆元計算
		facInv[i] = facInv[i - 1] * inv[i] % mod;
 	}

	if( n < k  || n < 0 || k < 0) return 0;
	return fac[n] * ( facInv[k] * facInv[n - k] % mod ) % mod;
 }
 
int main()
{
	ll n,m,k;cin>>n>>m>>k;
	ll comb = 0;
	
	REP(i,n) comb = ( comb + (i * (n-i)%cMOD) * (m * m%cMOD) ) % cMOD;
	REP(i,m) comb = ( comb + (i * (m-i)%cMOD) * (n * n%cMOD) ) % cMOD;
	
	comb = comb * combinationValue( n * m - 2, k-2, cMOD ) % cMOD;

	cout << comb << endl;
	
	return 0;
}