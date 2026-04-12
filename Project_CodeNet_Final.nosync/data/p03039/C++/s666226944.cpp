#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

typedef long long ll;
typedef pair<ll,ll> P;

#define MOD 1000000007

long long totient(long long a) {
	ll ret = a;
	for(int i = 2;i * i <= a;i++){
		if(a % i == 0){
			ret = ret * (i - 1) / i;
			while(a % i == 0)a /= i;
		}
	}
	if(a > 1)ret = ret * (a - 1) / a;
	return ret;
}

// a / b (mod p) b と p は互いに素
// O(sqrt(p))かかるので注意
long long totient_div(long long a, long long b, long long p) {
	long long ret = a;
	long long tp = totient(p) - 1;
	long long c = b;
	for(int i = 0;i <= 60;i++){
		if(tp & (1LL << i))ret = (ret * c) % p;
		c = (c * c) % p;
	}
	return ret;
}

//a^b % MOD
long long modpow(ll a,ll b){
	long long ret = 1;
	long long c = a;
	for(int i = 0;i <= 60;i++){
		if(b & (1LL << i))ret = (ret * c) % MOD;
		c = (c * c) % MOD;
	}
	return ret;
}

//ａをbで割る
long long mod_div(long long a,long long b){
	long long tmp = MOD - 2,c = b,ret = 1;
	while(tmp > 0){
		if(tmp & 1){
			ret *= c;ret %= MOD;
		}
		c *= c;c %= MOD;tmp >>= 1;
	}
	return a*ret%MOD;
}

#define MAX_K 333333
vector<long long> kaijo(MAX_K);
long long combination(long long n, long long r){
    if(n < r || n < 0 || r < 0)
        return 0;
	ll ue = 1;
	ll sita = 1;
	REP(i, r)ue = ue * (n - i) % MOD;
	REP(i, r)sita = sita * (i + 1) % MOD;
	return mod_div(ue, sita);
}

void modAdd(ll &a, ll b){
	a += b;
	a %= MOD;
}


int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	ll n, m, k;cin >> n >> m >> k;
	ll ans = 0;
	ll kake = combination((n * m - 2) % MOD, k - 2);

	REP(i, n){
		ll a, b;
		if(i == 0)a = m * (m - 1) % MOD;
		else a = m * m % MOD;
		b = n - i;
		modAdd(ans, (a * b % MOD) * i % MOD);
	}
	REP(i, m){
		ll a, b;
		if(i == 0)a = n * (n - 1) % MOD;
		else a = n * n % MOD;
		b = m - i;
		modAdd(ans, (a * b % MOD) * i % MOD);
	}

	cout << ans * kake % MOD << endl;

	return 0;
}
