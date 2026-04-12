#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<numeric>
#include<queue>
#include<deque>
#include<cfloat>
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#include<random>
#include<stdlib.h>
#define rip(i,n) for(int i=0;i<n;i++)
#define Rip(i,n) for(int i=1;i<=n;i++)
#define RIP(i,a,b) for(int i=a;i<b;i++)
#define all(V) V.begin(),V.end()
#define sec  setprecision;
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops");
constexpr double eps = 1e-9;
constexpr double pi = 3.141592653589793238462643383279;
using namespace std;
using ll = long long;
using ld = long double;
using Pa = pair<int, int>;
ll mod = 1000000007;
ll MOD = 998244353;
ll gcd(ll a, ll b)
{
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
ll pow(ll x, ll n) {
	x %= mod;
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return (pow((x * x) % mod, n / 2) % mod);
	else
		return (x * pow(x, n - 1)) % mod;
}
bool prime(int n) {
	int i = 2;
	if (n == 2)return true;
	else if(n <= 1)return false;
	if (n % i == 0)return false;
	i = 3;
	while (i <= sqrt(n)) {
		if (n % i == 0)return false;
		i += 2;
	}
	return true;
}
ll nextprime(ll sosuu, vector<bool>a) {
	sosuu++;
	while (a[sosuu] == false)sosuu++;
	return sosuu;
}
vector<bool> primes(ll n) {
	vector<bool>a(n, true);
	ll sosuu = 2;
	ll j = 2;
	while (sosuu * j < n)a[sosuu * j] = false, j++;
	while (sosuu < sqrt(n)+3) {
		j = 2;
		sosuu = nextprime(sosuu, a);
		while (sosuu * j < n)a[sosuu * j] = false, j++;
	}
	return a;
}
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
vector<ll>primess(ll n) {
	vector<ll>a;
	while (n % 2 == 0)n /= 2, a.push_back(2);
	ll sosuu = 3;
	while (n != 1) {
		if (n % sosuu == 0)n / sosuu, a.push_back(sosuu);
		else sosuu += 2;
	}
	return a;
}
signed main() {
	int n; cin >> n;
	if (n >= 30)cout << "Yes" << endl;
	else cout << "No" << endl;
}
