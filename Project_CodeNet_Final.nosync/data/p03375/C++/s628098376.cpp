#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3005;

ll C[MAXN][MAXN], S[MAXN][MAXN], ways[MAXN], pow2[MAXN * MAXN][2];

ll n, m;

ll qpow(ll a, ll b, ll c)
{
	if (b <= n * n)
		return pow2[b][(c == m - 1 ? 0 : 1)];
	ll ret = 1;
	for (; b; b >>= 1, a = a * a % c)
		if (b & 1)
			ret = ret * a % c;
	return ret;
}

void init()
{
	C[0][0] = 1;
	for (int i = 1; i <= n; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
	for (int i = 0; i <= n; i++)
		S[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + (j + 1) * S[i - 1][j] % m) % m;
	pow2[0][0] = pow2[0][1] = 1;
	for (int i = 1; i <= n * n; i++)
		(pow2[i][0] = pow2[i - 1][0] * 2) %= (m - 1), (pow2[i][1] = pow2[i - 1][1] * 2) %= m;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	init();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			(ways[i] += S[i][j] * qpow(2, (n - i) * j, m) % m * qpow(2, qpow(2, n - i, m - 1), m) % m) %= m;
	ll A = 0;
	for (int i = 0; i <= n; i++)
		(A += (i & 1 ? -1 : 1) * C[n][i] * ways[i] % m) %= m;
	if (A < 0)
		A += m;
	cout << A << endl;
	return 0;	
}
