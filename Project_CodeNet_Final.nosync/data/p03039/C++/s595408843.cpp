#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define sc second
#define ALL(x) x.begin(), x.end()
#define RALL(X) x.begin(), x.end()
#define FOR(i, n, k) for(i=0; i<n; i+=k)
#define FO(i, n, k) for(i=1; i<=n; i+=k)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define N 100005
#define mid ((l+r)/2)
#define dbg(x) (cerr << #x << " : " << x << endl)
#define endl "\n"
//#define MOD 100000007
#define MOD 1000000007

using namespace std;

typedef long long int lli;

const lli NMAX = 5LL * 100005LL;
lli fact[NMAX];
lli inv_fact[NMAX];
lli inv[NMAX];

lli c(lli a, lli b){
	return (fact[a] * ((inv_fact[a-b] * inv_fact[b]) % MOD)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1LL;

	inv[1] = 1LL;
	for(lli i=2LL; i<NMAX; i++)
	    inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;


	for(lli i=1LL; i<NMAX; i++){
		fact[i] = (i * fact[i-1]) % MOD;
		inv_fact[i] = (inv[i] * inv_fact[i-1]) % MOD;
	}

	lli n, m, k;
	cin >> n >> m >> k;
	lli d=0LL;

	for(lli i=0LL; i<n; i++){
		lli num = (n-i)*m*m % MOD;
		d = (d + i*num % MOD) % MOD;
	}	

	for(lli i=0LL; i<m; i++){
		lli num = (m-i)*n*n % MOD;
		d = (d + i*num % MOD) % MOD;
	}
	//dbg(c(200000, 100000));
	//d %= MOD;
	d *= c(n*m-2LL, k-2LL) % MOD;
	d %= MOD;
	cout << d << endl;
	return 0;
}