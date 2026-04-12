#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int h[N], st[N], top, n, ls[N], rs[N], root, f[N][2], num[N], single[N], mulsingle[N], rev[N], coe[N];
bool bsin[N];

inline void build()
{
	for (int i = 1; i <= n; i++)
	{
		int k = top;
		while (k > 0 && h[st[k]] > h[i]) k--;
		if (k) rs[st[k]] = i;
		if (k < top) ls[i] = st[k + 1];
		st[++k] = i;
		top = k;
	}
	root = st[1];
}

void dfs(int x)
{
	if (!x) return;
	cout << "x " << x << endl;
	dfs(ls[x]), dfs(rs[x]);
}

inline int fp(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res % mod;
}

inline void fill(int *a, int siz, int val)
{
	for (int i = 1; i <= siz; i++)	a[i] = val;
}

inline void dp(int x, int fa)
{
	if (!x) return;
	num[x] = 1;
	rev[x] = 1;
	coe[x] = 1;
	int height = h[x] - h[fa];
	// if (!rs[x] && !ls[x] && h[x] != h[fa])
	// {
	// 	single[x] = 1;
	// 	mulsingle[x] *= fp(2, height);
	// 	return;
	// }
	if (!rs[x] && !ls[x] && h[x] == h[fa])
		return;
	dp(ls[x], x);
	dp(rs[x], x);
	// if (ls[x] && x - ls[x] == 1) rev[x] += single[ls[x]];
	// if (rs[x] && rs[x] - x == 1) rev[x] += single[rs[x]];
	// if (ls[x]) mulsingle[x] *= mulsingle[ls[x]];
	// if (rs[x]) mulsingle[x] *= mulsingle[rs[x]]; 
	if (ls[x] && h[ls[x]] == h[x]) rev[x] += rev[ls[x]], coe[x] = (coe[ls[x]] * coe[x]) % mod;
	if (rs[x] && h[rs[x]] == h[x]) rev[x] += rev[rs[x]], coe[x] = (coe[rs[x]] * coe[x]) % mod;
	if (f[ls[x]][1] == 0) ls[x] = 0;
	if (f[rs[x]][1] == 0) rs[x] = 0;
	if (h[x] != h[fa]) coe[x] = 2;
	if (height > 0)
	{
		if (rs[x] && ls[x])
		{
			f[x][1] = f[rs[x]][1] * f[ls[x]][1] % mod * fp(2, height) % mod;
			// cout << "fk1 " << f[rs[x]][1] << ' ' << f[ls[x]][1] << endl;
			// cout << "fk0 " << f[rs[x]][0] << ' ' << f[ls[x]][0] << endl;
			// f[x][0] = (((f[rs[x]][1] * f[ls[x]][0] % mod * coe[rs[x]] % mod * fp(2, rev[x]) % mod + 
			// 	f[rs[x]][0] * f[ls[x]][1] % mod * coe[ls[x]] % mod * fp(2, rev[x]) % mod) % mod + 
			// f[rs[x]][0] * f[ls[x]][0] % mod * fp(2, rev[x]) % mod) % mod + 
			// f[rs[x]][1] * f[ls[x]][1] % mod * (coe[rs[x]] % mod * coe[ls[x]] % mod * fp(2, rev[x]) - 2 + mod) % mod) % mod;
			f[x][0] = f[rs[x]][1] * f[ls[x]][0] % mod * coe[rs[x]] % mod * fp(2, rev[x]) % mod;
			f[x][0] = (f[x][0] + f[rs[x]][0] * f[ls[x]][1] % mod * coe[ls[x]] % mod * fp(2, rev[x]) % mod) % mod;
			f[x][0] = (f[x][0] + f[rs[x]][0] * f[ls[x]][0] % mod * fp(2, rev[x]) % mod) % mod;
			f[x][0] = (f[x][0] + f[rs[x]][1] * f[ls[x]][1] % mod * (coe[rs[x]] % mod * coe[ls[x]] % mod * fp(2, rev[x]) % mod - 2 + mod) % mod) % mod;

		}
		else if (rs[x])
		{
			f[x][1] = f[rs[x]][1] * fp(2, height) % mod;
			f[x][0] = (f[rs[x]][0] * fp(2, rev[x]) % mod + f[rs[x]][1] * ((coe[rs[x]] * fp(2, rev[x]) % mod - 2 + mod) % mod)) % mod;
			// cout << "f[rs[x]][0] " << f[rs[x]][0] << endl;
			// cout << "f[rs[x]][1] " << f[rs[x]][1] << endl;
			// cout << "coe[rs[x]] " << coe[rs[x]] << endl;
			// cout << "rev[x] " << rev[x] << endl;
			// cout << "fk " << f[x][0] << endl;
		}
		else if (ls[x])
		{
			f[x][1] = f[ls[x]][1] * fp(2, height) % mod;
			f[x][0] = (f[ls[x]][0] * fp(2, rev[x]) % mod + f[ls[x]][1] * ((coe[ls[x]] * fp(2, rev[x]) % mod - 2 + mod) % mod)) % mod;
		}
		else 
		{
			f[x][1] = fp(2, height);
			f[x][0] = (fp(2, rev[x]) - 2 + mod) % mod;
		}
	}	
	else 
	{
		if (rs[x] && ls[x])
		{
			if (h[rs[x]] != h[x])
				coe[x] = (coe[x] * 2) % mod;
			if (h[ls[x]] != h[x])
				coe[x] = (coe[x] * 2) % mod;
			f[x][1] = f[rs[x]][1] * f[ls[x]][1] % mod;
			f[x][0] = ((f[rs[x]][0] * f[ls[x]][0] % mod + f[rs[x]][1] * f[ls[x]][0] % mod * coe[rs[x]] % mod) % mod + f[rs[x]][0] * f[ls[x]][1] % mod * coe[ls[x]] % mod) % mod;
		}
		else if (rs[x])
		{
			f[x][1] = f[rs[x]][1];
			f[x][0] = f[rs[x]][0];
			if (h[rs[x]] != h[x])
			coe[x] = (2 * coe[x]) % mod;
		}
		else if (ls[x])
		{
			f[x][1] = f[ls[x]][1];
			f[x][0] = f[ls[x]][0];
			if (h[ls[x]] != h[x])
			coe[x] = (2 * coe[x]) % mod;
		}
	}
	// cout << "x " << x << endl;
	// cout << "f[x][1] " << f[x][1] << endl;
	// cout << "f[x][0] " << f[x][0] << endl;
	// cout << "rev[x] " << rev[x] << endl;
	// cout << "coe[x] " << coe[x] << endl;
	coe[x] %= mod;
	f[x][1] %= mod;
	f[x][0] %= mod;
}

signed main()
{
	int ml = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> h[i];
	if (n == 1)
	{
		cout << fp(2, h[1]) << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (h[i] > h[i - 1] && h[i] > h[i + 1]) ml += h[i] - max(h[i - 1], h[i + 1]), h[i] = max(h[i - 1], h[i + 1]);
	build();
	fill(mulsingle, n, 1);
	f[0][1] = f[0][0] = 1;
	dp(root, 0);
	// cout << "mul " << fp(2, ml) << endl;
	cout << (f[root][1] + f[root][0]) % mod * fp(2, ml) % mod << endl;
	// cout << "1 " << f[root][1] << endl;
	// cout << "0 " << f[root][0] << endl;
	return 0;
}