#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 998244353;
#define SIZE 100000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
#define LOG 14
class NTT
{
public:
	ll dat[2][1 << LOG];
	ll omega[1 << LOG], romega[1 << LOG];
	int seg[1 << LOG];
	ll m, root;
	ll po(ll a, ll b)
	{
		if (b == 0)return 1;
		ll z = po(a, b / 2);
		z = z*z%m;
		if (b & 1)z = z*a%m;
		return z;
	}
	ll inv(ll a)
	{
		return po(a, m - 2);
	}
	void findroot(ll mm, int lg)//引数はmod 位数 1<<lg の元を返す 提出時は呼ばない
	{
		for (int i = 2;; i++)
		{
			ll now = 1;
			bool f = false;
			for (int j = 0; j < mm - 1; j++)
			{
				now = now*i%mm;
				if (now == 1)
				{
					printf("%d %d\n", i, j);
					if (j == mm - 2)
					{
						ll r = 1;
						for (int k = 0; k < ((mm - 1) >> lg); k++)r = r*i%mm;
						cerr << r << " is root" << endl;
						return;
					}
					else break;
				}
			}
		}
	}
	void init(ll modulo, ll primeroot, int lg)
	{
		m = modulo, root = primeroot;
		ll ir = inv(root);
		omega[0] = romega[0] = 1;
		for (int i = 1; i < (1 << lg); i++)omega[i] = omega[i - 1] * root%m;
		for (int i = 1; i < (1 << lg); i++)romega[i] = romega[i - 1] * ir%m;
		for (int i = 0; i < (1 << lg); i++)
		{
			int t = 0;
			for (int j = 0; j < lg; j++)if (i&(1 << j))t += 1 << (lg - j - 1);
			seg[i] = t;
		}
	}
	vector<ll>transform(vector<ll>v, int lg, bool pal)//サイズ2^lg, palは順変換のときtrue, 逆変換のときfalse
	{
		int cur = 0;
		v.resize(1 << lg);
		for (int i = 0; i < (1 << lg); i++)dat[0][seg[i]] = v[i];
		for (int i = lg - 1; i >= 0; i--)
		{
			for (int j = 0; j < (1 << lg); j += (1 << (lg - i)))
			{
				int s = 1 << (lg - i - 1);
				if (pal)
				{
					for (int k = 0; k < s; k++)dat[1 - cur][j + k] = (dat[cur][j + k] + dat[cur][j + s + k] * omega[k << i]) % m;
					for (int k = 0; k < s; k++)dat[1 - cur][j + s + k] = (dat[cur][j + k] + dat[cur][j + s + k] * (m - omega[k << i])) % m;
				}
				else
				{
					for (int k = 0; k < s; k++)dat[1 - cur][j + k] = (dat[cur][j + k] + dat[cur][j + s + k] * romega[k << i]) % m;
					for (int k = 0; k < s; k++)dat[1 - cur][j + s + k] = (dat[cur][j + k] + dat[cur][j + s + k] * (m - romega[k << i])) % m;
				}
			}
			cur = 1 - cur;
		}
		vector<ll>ret;
		for (int i = 0; i < (1 << lg); i++)ret.push_back(dat[cur][i]);
		return ret;
	}
	vector<ll>mul(vector<ll>a, vector<ll>b, int lg)//aとbの畳み込みを計算
	{
		a = transform(a, lg, true);
		b = transform(b, lg, true);
		for (int i = 0; i < a.size(); i++)a[i] = a[i] * b[i] % m;
		a = transform(a, lg, false);
		ll t = inv(1 << lg);
		for (int i = 0; i < a.size(); i++)a[i] = a[i] * t%m;
		return a;
	}
};
NTT ntt;
ll dp[210][8100];
ll root = 666702199;
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	invinit();
	ntt.init(mod, root, LOG);
	dp[0][0] = 1;
	vector<ll>m;
	for (int i = 3; i <= mx + 2; i++)m.push_back(invkai[i]);
	m = ntt.transform(m, LOG, true);
	for (int i = 0; i < my; i++)
	{
		vector<ll>v;
		for (int j = 0; j <= mx; j++)v.push_back(dp[i][j] * invkai[j] % mod);
		v = ntt.transform(v, LOG, true);
		for (int j = 0; j < v.size(); j++)v[j] = v[j] * m[j] % mod;
		v = ntt.transform(v, LOG, false);
		for (int j = 0; j < mx; j++)dp[i + 1][j + 1] = v[j] * kai[j + 3] % mod*inv[1 << LOG] % mod;
		for (int j = 0; j <= mx; j++)dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (com(j + 1, 2) + 1)) % mod;
	}
	ll ans = 0;
	for (int i = 0; i <= mx; i++)ans += dp[my][i] * com(mx, i), ans %= mod;
	printf("%lld\n", ans);
}
