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
string a, b, c;
int A, B, C;

ll pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = res * x % mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}


ll calc(int k)
{
	if (k < C) return 0;
	ll res = (k - C) * 9 * pow(10, k - C - 1, MOD);
	res %= MOD;
	res += pow(10, k - C, MOD);
	return res % MOD;
}

ll toint(string s)
{
	ll res = 0;
	REP(i, s.size())
	{
		res *= 10;
		res += s[i] - '0';
		res %= MOD;
	}
	return res%MOD;
}

void dec()
{
	if (a == "0")
	{
		a = "";
		return;
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] == '0')
		{
			a[i] = '9';
		}
		else if (i == 0 && a[i] == '1')
		{
			a.erase(0, 1);
		}
		else
		{
			a[i]--;
			break;
		}
	}
}

void zero()
{
	ll ans = 0;
	FOR(i, A, B)
	{
		if (i == 0) continue;
		if (i == 1) ans++;
		else
		{
			ll tmp = 9 * (i - 1)*pow(10, i - 2, MOD);
			ans = (ans + tmp) % MOD;
		}
	}

	REP(i, A - C + 1)
	{
		if (i == 0) continue;
		if (i != 0)
		{
			ll tmp = 0;
			tmp += (a[0] - '1')*pow(10, i - 1, MOD);
			tmp %= MOD;
			ll x = toint(a.substr(1, i - 1));
			if (a.substr(i, C) != "0")
			{
				x++;
				tmp += x;
				tmp = tmp * pow(10, A - C - i, MOD) % MOD;
				ans = (ans - tmp + MOD) % MOD;
			}
			else
			{
				tmp += x;
				tmp = tmp * pow(10, A - C - i, MOD) % MOD;
				tmp += toint(a.substr(i + 1)) + 1;
				ans = (ans - tmp + MOD) % MOD;
			}
		}
	}
	REP(i, B - C + 1)
	{
		if (i == 0) continue;
		if (i != 0)
		{
			ll tmp = 0;
			tmp += (b[0] - '1')*pow(10, i - 1, MOD);
			tmp %= MOD;
			ll x = toint(b.substr(1, i - 1));
			if (b.substr(i, C) != "0")
			{
				x++;
				tmp += x;
				tmp = tmp * pow(10, B - C - i, MOD) % MOD;
				ans = (ans + tmp + MOD) % MOD;
			}
			else
			{
				tmp += x;
				tmp = tmp * pow(10, B - C - i, MOD) % MOD;
				tmp += toint(b.substr(i + 1)) + 1;
				ans = (ans + tmp + MOD) % MOD;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	cin >> a >> b >> c;
	dec();
	A = a.size(), B = b.size(), C = c.size();
	if (c == "0")
	{
		zero();
		return 0;
	}
	ll ans = 0;
	FOR(i, A, B) ans = (ans + calc(i)) % MOD;

	REP(i, A - C + 1)
	{
		if (i != 0)
		{
			ll tmp = 0;
			tmp += (a[0] - '1')*pow(10, i - 1, MOD);
			tmp %= MOD;
			ll x = toint(a.substr(1, i - 1));
			if (a.substr(i, C) >= c) x++;
			tmp += x;
			tmp = tmp * pow(10, A - C - i, MOD) % MOD;
			ans = (ans - tmp + MOD) % MOD;
		}
		else
		{
			if (a.substr(i, C) == c)
			{
				ll tmp = toint(a.substr(a.size() - C, C)) + 1;
				ans = (ans - tmp + MOD) % MOD;
			}
			else if (a.substr(i, C) > c)
			{
				ll tmp = pow(10, A - C, MOD);
				ans = (ans - tmp + MOD) % MOD;
			}
		}
	}
	REP(i, B - C + 1)
	{
		if (i != 0)
		{
			ll tmp = 0;
			tmp += (b[0] - '1')*pow(10, i - 1, MOD);
			tmp %= MOD;
			ll x = toint(b.substr(1, i - 1));
			if (b.substr(i, C) >= c) x++;
			tmp += x;
			tmp = tmp * pow(10, B - C - i, MOD) % MOD;
			ans += tmp;
			ans %= MOD;
		}
		else
		{
			if (b.substr(i, C) == c)
			{
				ll tmp = toint(b.substr(b.size() - C, C)) + 1;
				ans = (ans + tmp) % MOD;
			}
			else if (b.substr(i, C) > c)
			{
				ll tmp = pow(10, B - C, MOD);
				ans = (ans + tmp) % MOD;
			}
		}
	}
	cout << ans << endl;
	return 0;
}