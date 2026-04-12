#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define lli long long int
#define pii pair<int, int>
#define vii vector<pii>
#define pb push_back
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define vi vector<int>
#define vl vector<lli>
#define vll vector<pair<lli, lli>>
#define pll pair<lli, lli>
#define vvi vector<vector<int>>
#define vvl vector<vector<lli>>
#define error(args...)                           \
	{                                            \
		string _s = #args;                       \
		replace(_s.begin(), _s.end(), ',', ' '); \
		stringstream _ss(_s);                    \
		istream_iterator<string> _it(_ss);       \
		err(_it, args);                          \
	}
#define tk(args...) take(args);
#define posLSB(X) __builtin_ctz(X)
#define num1bit(X) __builtin_popcount(X)
#define numlead0(X) __builtin_clz(X)
#define umreserve(X)  \
	X.reserve(32768); \
	X.max_load_factor(0.25);
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << *it << " = " << a << "\n";
	err(++it, args...);
}
void take() {}
template <typename T, typename... Args>
void take(T &a, Args &... args)
{
	cin >> a;
	take(args...);
}
template <class T>
void printvec(vector<T> &a)
{
	for (T &x : a)
	{
		cout << x << " ";
	}
	cout << endl;
}
template <class T>
void printarr(T a[], lli n)
{
	for (lli i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
struct HASH
{
	size_t operator()(const pair<int, int> &x) const
	{
		return (size_t)x.first * 37U + (size_t)x.second;
	}
};

#define endl "\n"

lli add(lli a, lli b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

lli mul(lli a, lli b)
{
	return a * 1ll * b % mod;
}

inline bool setmin(lli &x, lli y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(lli &x, lli y) { return (y > x) ? x = y, 1 : 0; }

lli power_mod(lli a, lli x)
{
	if (x == 0)
		return 1;
	lli y = power_mod(a, x / 2);
	lli ans = (y * y) % mod;
	if (x % 2)
		ans = (ans * a) % mod;
	return ans;
}
lli inv(lli a) { return power_mod(a, mod - 2); }
lli power(lli a, lli x)
{
	if (x == 0)
		return 1;
	lli y = power(a, x / 2);
	lli ans = (y * y);
	if (x % 2)
		ans *= a;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string k;
	cin >> k;
	int d;
	cin >> d;
	vector<vector<lli>> dp(d, vector<lli>(2));
	dp[0][0] = 1;
	for (int where = 0; where < k.size(); where++)
	{
		vector<vector<lli>> newdp(d, vector<lli>(2));
		for (bool sal : {false, true})
		{
			for (int x = 0; x < 10; x++)
			{
				if (!sal && x > k[where] - '0')
					break;
				for (int s = 0; s < d; s++)
				{
					newdp[(s + x) % d][sal || (x < k[where] - '0')] = add(newdp[(s + x) % d][sal || (x < k[where] - '0')], dp[s][sal]);
				}
			}
		}
		dp = newdp;
	}
	cout << add(add(dp[0][1], dp[0][0]),mod-1) << endl;
}
