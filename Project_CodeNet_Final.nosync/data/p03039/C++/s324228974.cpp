#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n)  for(int i=0;i<(n);++i)
#define REPr(i, n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m, n) for(int i = (n);i >=(m);--i)
#define PB push_back
#define MP make_pair
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x, y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const ll MOD = 1000000007;

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

template<class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
///////////////////////////////////////////////
/*（๑•﹏•๑｀) */

const int p = 1000000007;
const int NMAX = 310000;
ll fac[NMAX],finv[NMAX],inv[NMAX];
void combinit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;

	FORq(i,2,NMAX-1){
		fac[i] = fac[i-1] * i % p;
		inv[i] = p - inv[p%i] * (p / i) % p;
		finv[i] = finv[i-1] * inv[i] % p;
	}
}
long long comb(ll n,int r){
	if (n<r) return 0;
	if (n < 0 || r < 0) return 0;
	return fac[n] * (finv[r] * finv[n-r] % p) % p;
}

int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    combinit();

    ll ans = 0;
    ll ansA = 0;
    for(ll d = 1;d <= N-1; d++){
		ansA =  ansA + d*(N-d);
    }
    ansA = (ansA * ((M * M) % p) % p);
    ans = (ans + ansA) % p;
    ansA = 0;

    swap(N,M);

	for(ll d = 1;d <= N-1; d++){
		ansA =  ansA + d*(N-d);
	}
	ansA = (ansA * ((M * M) % p) % p);
	ans = (ans + ansA) % p;
	ansA = 0;

	ans *= comb(N*M-2,K-2);
	ans = ans % p;
    if (ans < 0) ans += p;
    cout << ans << "\n";
}