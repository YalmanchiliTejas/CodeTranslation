#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 9999999999
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define int long long


using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[9] = { 0, 0,0,1,1,1,-1,-1,-1 };
int dyy[9] = { 0, 1,-1,0,1,-1,0,1,-1 };




ll gcd(ll x, ll y) {
	ll m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}

long long power_mod(long long x, long long n, long long m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power_mod(x * x % m, n / 2, m);
	else
		return x * power_mod(x, n - 1, m) % m;
}

long long power(long long a, long long n) {//aのn乗を計算します。
	long long x = 1;
	while (n > 0) {//全てのbitが捨てられるまで。
		if (n & 1) {//1番右のbitが1のとき。
			x = x * a;
		}
		a = a * a;
		n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
	}
	return x;
}



long long nCr(long long n, long long r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	long long i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}



const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

bool arr[100000100];
vector<ll>sosuu;
void Eratosthenes() {
	ll N = 10000010;
	int c = 0;
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	for (ll i = 2; i < sqrt(N); i++) {
		if (arr[i]) {
			for (ll j = 0; i * (j + 2) < N; j++) {
				arr[i *(j + 2)] = 0;
			}
		}
	}

	for (ll i = 2; i < N; i++) {
		if (arr[i]) {
			sosuu.pb(i);
			//cout << sosuu[c] << " ";
			c++;
		}
	}
	//cout << endl;
	//cout << c << endl;
}

ll stoL(string s) {
	ll n = s.length();
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += power(10, n - i - 1)*(ll)(s[i] - '0');
	}
	return ans;
}

bool comp(string x, string y) {
	if (x.length() > y.length())return true;
	else if (x.length() < y.length())return false;
	else return x > y;
}


ll dp[3030][3030];
ll a[3030];
int N;

bool flag[3030][3030];
int rec(int l,int r) {
	if (flag[l][r])return dp[l][r];
	flag[l][r] = 1;
	if (l == r)return dp[l][r] = a[l];
	return dp[l][r] = max(a[l] - rec(l + 1, r), a[r] - rec(l,r - 1));
}

signed main() {
	REP(i, 3030)REP(j, 3030)flag[i][j] = 0;
	cin >> N;
	REP(i, N)cin >> a[i];
	print(rec(0, N - 1));
}


