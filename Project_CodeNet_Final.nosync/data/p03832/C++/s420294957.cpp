#include <bits/stdc++.h>

using namespace std;

using LL = long long;           using PII = pair<int, int>;
using ll = long long;           using DBL = double;
using VI = vector<int>;         using VD = vector<DBL>;
using VVI = vector<VI>;         using VVD = vector<VD>;
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i,n) FOR(i,0,n)
#define SZ(a) ((int)((a).size()))
#define ALL(x) (x).begin(), (x).end()
#define SET(a,v) memset((a), (v), sizeof(a))
#define EB emplace_back #define PB push_back
#define MP make_pair  #define ST first  #define ND second

// #define trace(...) {__f(#__VA_ARGS__, __VA_ARGS__);}
// template<typename Arg> void __f(const char* name, Arg&& arg) {
//   cerr << name << " = " << arg << std::endl;
// } template <typename Arg1, typename... Args>
// void __f(const char* names, Arg1&& arg1, Args&&... args) {
//   const char* comma = strchr(names + 1, ',');
//   cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...); }
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds; // OST: find_by_order, order_of_key
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// #pragma GCC optimize("Ofast")
// optimize("unroll-loops")
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// /*** RNGS ***/
// SEED=chrono::steady_clock::now().time_since_epoch().count();
// // or high_resolution_clock
// mt19937 rng(SEED); /*or*/ random_device rd; mt19937 rng(rd());
// uniform_int_distribution<> dis(MIN, MAX);// usage: dis(rng)
// struct chash {int operator()(int x) const {return x^SEED;}};
// gp_hash_table<int,int,chash>m;//use cc if very less updates
// /*** FAST IO ***/
// inline int scan(){ bool y=0; int x=0; char c=getchar_unlocked();
// while(c<'0'||c>'9'){ if(c=='-')y=1; c=getchar_unlocked();} 
// while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar_unlocked();}
// return y?-x:x; }

int a, b, c, d;
int dp[1024][1024];
const int MOD = 1000000007;
int fact[1024], ifact[1024];

int powmod(int a, int b) {
	if(!b) return 1;
	if(b&1) return (a * 1ll * powmod(a, b-1))%MOD;
	return powmod((a*1ll*a)%MOD, (b/2));
}

int C(int n, int r) {
	return (fact[n] * 1ll * ((ifact[r] * 1ll * ifact[n-r])%MOD) ) % MOD;
}

int calc(int n, int p) {
	int &y = dp[n][p];
	if(y != -1) return y;
	if(p == a-1) return y = (n == 0);
	y = calc(n, p-1);
	if(p*c <= n) {
		int coeff = (C(n, p*c) * 1ll * fact[p*c]) % MOD;
		coeff = (coeff * 1ll * powmod(ifact[p], c)) % MOD;
		for(int i=c; i<=d; ++i) {
			if(p*i > n) break;
			y = (y + (((coeff *1ll* calc(n-p*i, p-1))%MOD) * 1ll * ifact[i])) % MOD;
			if(p*(i+1) > n) break;
			coeff = (C(n-p*i, p) * 1ll * coeff) % MOD;
		}
	}
	return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for(int i=1; i<=1001; ++i) {
    	fact[i] = (i * 1ll * fact[i-1]) % MOD;
    }
    ifact[0] = 1;
    for(int i=1; i<=1001; ++i) {
    	ifact[i] = powmod(fact[i], MOD-2);
    }
    int n;
    cin >> n >> a >> b >> c >> d;
    SET(dp, -1);
    cout << calc(n, b) << endl;
    return 0;
}