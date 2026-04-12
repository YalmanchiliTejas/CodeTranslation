#define NDEBUG
#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define repD(i,t,s) for(int i = (int)(t); i >= (int)(s); --i)
#define rep(i,n) repU(i,0,n - 1)
#define rep1(i,n) repU(i,1,n)
#define all(v) begin(v),end(v)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n - 1) / (d) + 1)
#define parity(a,b) (((a)^(b)) & 1 ^ 1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = (1 << 30) - 1;
const ll INF_64 = (1LL << 62) - 1;
const int MOD = 1e9 + 7;

ll Pow(ll n, ll m, int mod = MOD){
	ll res = 1,pow = n % mod;
	while(m) {
		if(m & 1LL) res = (res * pow) % mod;
		pow = (pow * pow) % mod;
		m >>= 1;
	}
	return res;
}

ll Inv(ll n, int mod = MOD){ return Pow(n % mod, mod - 2, mod); }

void Fact_table(ll *fact, int range, int mod = MOD){
	fact[0] = 1;
	rep1(i,range) fact[i] = fact[i - 1] * i % mod;
}

void Fact_inv_table(ll *fact_inv, ll *fact, int range, int mod = MOD){
	rep(i,range + 1) fact_inv[i] = Inv(fact[i]);
}

ll Comb(int n, int m, ll *fact, ll *fact_inv, int mod = MOD){
	if(n < m || m < 0) return 0;
	ll rev = fact_inv[m] * fact_inv[n - m] % mod;
	return rev * fact[n] % mod;
}

int N,A,B,C,D;
ll fact[1010],fact_inv[1010],memo[1010][1010];

ll cal(int m, int x, int y){
	int cur = x * y;
	ll res = Comb(m,cur,fact,fact_inv);
	if(memo[x][y] < 0){
		memo[x][y] = 1;
		while(cur){
			memo[x][y] = memo[x][y] * Comb(cur,x,fact,fact_inv) % MOD;
			cur -= x;
		}
	}
	res = res * memo[x][y] % MOD;
	return res * fact_inv[y] % MOD;
}

void solve(){
	ll dp[1010] = {};
	dp[0] = 1;
	repD(i,B,A){
		repD(j,N,1){
			dp[j] = dp[j];
			repU(k,C,D){
				if(j < i * k) break;
				dp[j] += dp[j - i * k] * cal(j,i,k);
				dp[j] %= MOD;
			}
		}
	}
	cout << dp[N] << endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	rep(i,1010) fill(all(memo[i]),-1);
	Fact_table(fact,1005);
	Fact_inv_table(fact_inv,fact,1005);
	cin >> N >> A >> B >> C >> D;
	solve();
}




