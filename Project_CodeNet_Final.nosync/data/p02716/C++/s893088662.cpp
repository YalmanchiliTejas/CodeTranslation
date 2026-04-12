#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <random>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b)
{
	ll res = 1;
	a %= mod;
	assert(b >= 0);
	for (; b; b >>= 1)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

static uint MD = mod;
struct ModInt
{
	using M = ModInt;
	uint v;
	ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
	M &set_v(uint _v)
	{
		v = (_v < MD) ? _v : _v - MD;
		return *this;
	}
	explicit operator bool() const { return v != 0; }
	M operator-() const { return M() - *this; }
	M operator+(const M &r) const { return M().set_v(v + r.v); }
	M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
	M operator*(const M &r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
	M operator/(const M &r) const { return *this * r.inv(); }
	M &operator+=(const M &r) { return *this = *this + r; }
	M &operator-=(const M &r) { return *this = *this - r; }
	M &operator*=(const M &r) { return *this = *this * r; }
	M &operator/=(const M &r) { return *this = *this / r; }
	bool operator==(const M &r) const { return v == r.v; }
	M pow(ll n) const
	{
		M x = *this, r = 1;
		while (n)
		{
			if (n & 1)
				r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	M inv() const { return pow(MD - 2); }
	friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};
using Mint = ModInt;
//head
// cin >> t;
// for (int cas = 1; cas <= t; ++cas)
// {
// 	cout << "Case #" << cas << ": ";
// }
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,0,n) {
		cin>>a[i];
	}
	vector<ll> dp(n+1,0);
	ll tmps = a[0];
	rep(i,2,n+1) {
		if(i&1) {
			tmps += a[i-1];
			dp[i] = max(a[i-1] + dp[i-2], dp[i-1]);
		}
		else {
			dp[i] = max(a[i-1] + dp[i-2], tmps);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
