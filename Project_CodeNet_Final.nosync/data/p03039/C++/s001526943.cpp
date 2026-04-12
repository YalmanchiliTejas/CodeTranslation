#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORALL(i, m) for( auto i = m.begin(); i != m.end() ; ++i )
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define TM_T template <class T>
#define MOD 1000000007l
using namespace std;
typedef long long ll;
TM_T T inp(){T it;cin >> it;return it;}

ll N, M, K;

// n^m%MOD を求める。O( log(m) )
ll modpow(ll n, int m){
	ll ret=1;
	for(int i=1; i<=m; i<<=1, (n*=n)%=MOD){
		if( m&i ) (ret *= n) %= MOD;
	}
	return ret;
}
 
// 逆元を求める
ll moddiv(ll n){
	return modpow( n, MOD-2 );
}
 
// 階乗を求める。O(1)  準備O( n*log(n) )
// fact[n]     : nの階乗
// fact.inv[n] : nの階乗の逆元
class FACTORIAL{
public:
	const int MAX_NUM = 1000006; // 最大のn
	vector<ll> fact;
	vector<ll> inv;
	FACTORIAL(): fact(MAX_NUM), inv(MAX_NUM) {
		fact[0] = 1;
		for(ll i=1; i<MAX_NUM; i++){
			fact[i] = (fact[i-1] * i) % MOD;
			inv[i] = modpow( fact[i], MOD-2 );
		}
	}
	const ll& operator [ ] ( const int i ) const {
		return fact[i];
	}
} fact;
 
 
// 組み合わせ(Combinationを求める) O(1)
ll Cmb(unsigned int n, unsigned int r){
    if (n==r)return 1;
    if (r==0)return 1;
	if( n < r ) return 0;
	return fact[n] * fact.inv[r] % MOD * fact.inv[n-r] % MOD;
}

int input(){
  cin >> N >> M >> K;
}

int main()
{
  input();
  
  ll s = 0;
  FOR(d,1,N+1){
    ll s2 = 1;
    s2=(s2*d)%MOD;
    s2=(s2*M)%MOD;
    s2=(s2*M)%MOD;
    s2=(s2*(N-d))%MOD;
    s2=(s2*Cmb(N*M-2,K-2))%MOD;
    s=(s+s2)%MOD;
  }
  FOR(d,1,M+1){
    ll s2 = 1;
    s2=(s2*d)%MOD;
    s2=(s2*N)%MOD;
    s2=(s2*N)%MOD;
    s2=(s2*(M-d))%MOD;
    s2=(s2*Cmb(N*M-2,K-2))%MOD;
    s=(s+s2)%MOD;
  }
  
  cout << s << endl;
  
  
}