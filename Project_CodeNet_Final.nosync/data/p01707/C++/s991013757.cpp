#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

const ll mod = 1000000007;
struct Mod
{
	ll num;
	Mod() : num(0) { ; }
	Mod(ll n) : num(n % mod) { ; }
	operator ll() { return num; }
};


Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }
Mod operator^(Mod a, ll n)
{
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod inv(Mod a) { return a ^ (mod - 2); }
Mod operator/(Mod a, Mod b) { return a * inv(b); }

Mod fact(Mod n)
{
	if (n < 0) assert(false);
	if (n == 0 || n == 1) return 1;
	else return n*fact(n - (Mod)1);
}

Mod nPk(Mod n, Mod k)
{
	if (n < 0 || k < 0 || n < k) assert(false);
	return fact(n) / fact(k);
}

Mod nCk(Mod n, Mod k)
{
	if (n < 0 || k < 0 || n < k) assert(false);
	return nPk(n, k) / fact(n - k);
}

Mod nHk(Mod n, Mod k)
{
	if (n < 0 || k < 0 || n < k) assert(false);
	return nCk(n + k - (Mod)1, k);
}


ll n, d, x;
Mod dp[2222][2222];
int main()
{
	while (cin >> n >> d >> x, n)
	{
		REP(i, 2222)REP(j, 2222) dp[i][j] = 0;
		Mod N(n), D(d);
		dp[0][0] = 1;
		FOR(i, 1, n + 1)FOR(j, 1, n + 1)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			if (j >= x) dp[i][j] -= dp[i - 1][j - x];
		}
		Mod ans = 0;
		FOR(i, 1, min(d + 1, n + 1))
		{
			Mod tmp = (Mod)dp[i][n];
			REP(j, i)
			{
				tmp = (Mod)(d - j + mod)*tmp;
				tmp = tmp*inv(Mod(i - j + mod));
			}
			ans += tmp;
		}
		cout << ans << endl;
	}
	return 0;
}