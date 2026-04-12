# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(13);
    }
}INIT;

const LL MOD = 1000000007;
LL combi(LL N_, LL C_) {
	const int NUM_ = 1010101;
	static LL fact[NUM_ + 1], factr[NUM_ + 1], inv[NUM_ + 1];
	if (fact[0] == 0) {
		inv[1] = fact[0] = factr[0] = 1;
		for (int i = 2; i <= NUM_; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		for (int i = 1; i <= NUM_; ++i) fact[i] = fact[i - 1] * i%MOD, factr[i] = factr[i - 1] * inv[i] % MOD;
	}
	if (C_<0 || C_>N_) return 0;
	return factr[C_] * fact[N_] % MOD*factr[N_ - C_] % MOD;
}

LL hcomb(int P_, int Q_) { return (P_ == 0 && Q_ == 0) ? 1 : combi(P_ + Q_ - 1, Q_); }

LL modpow(LL a, LL n = MOD - 2) {
	LL r = 1;
	while (n) r = r*((n % 2) ? a : 1) % MOD, a = a*a%MOD, n >>= 1;
	return r;
}

// a x + b y = gcd(a, b)
LL extgcd(LL a, LL b, LL &x, LL &y) {
    LL g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

// mod m ?? a ? ??
LL mod_inverse(LL a, LL m){
    LL x, y;
    extgcd(a, m, x, y);
    return (m + x%m)%m;
}

long long power(long long n, long long k, long long m) {
	if (k == 0) {
		return 1;
	}
	else if (k % 2 == 1) {
		return power(n, k - 1, m)*n%m;
	}
	else {
		long long t = power(n, k / 2, m);
		return t*t%m;
	}
}

LL fact[1010101];

int n, a, b, c, d;
LL dp[1010][1010];
int main(){
    fact[0] = 1;
    for(int i = 1;i < 1010101;i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
    cin >> n >> a >> b >> c >> d;
    dp[a - 1][0] = 1;
    for(int i = a;i <= b;i++){
        for(int j = 0;j <= n;j++){
            dp[i][j] += dp[i - 1][j];
            LL power_k = power(fact[i], c, MOD);
            for(int k = c;k <= d;k++){
                int old_j = j - i*k;
                if(old_j < 0)break;
                LL num = 1;
                num *= dp[i - 1][old_j];
                (num *= combi(n - old_j, i * k)) %= MOD;
                (num *= fact[i * k]) %= MOD;
                (num *= mod_inverse(power_k, MOD)) %= MOD;
                (num *= mod_inverse(fact[k], MOD)) %= MOD;
                (dp[i][j] += num) %= MOD;

                (power_k *= fact[i]) %= MOD;
            }
        }
    }
    cout << dp[b][n] << endl;
}