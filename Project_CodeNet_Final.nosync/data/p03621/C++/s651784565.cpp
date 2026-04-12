#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MOD = 998244353;

const int MAX = 10010;

int DP[MAX][MAX];

char buf[MAX];
int A[MAX];
int B[MAX];

LL F[MAX];

LL bpow(LL a, LL b)
{
	LL res = 1;
	while(b)
	{
		if (b & 1) res = (res * a) % MOD;
		b /= 2;
		a = (a * a) % MOD;
	}

	return res;
}

LL inv(LL a)
{
	return bpow(a, MOD - 2);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	F[0] = 1;
	FOR (i, 1, MAX)
	{
		F[i] = (F[i-1] * (LL)i) % MOD;
	}

	scanf("%s", buf);
	int n = strlen(buf);
	FOR (i, 0, n)
	{
		A[i] = buf[i] - '0';
	}

	scanf("%s", buf);
	FOR (i, 0, n)
	{
		B[i] = buf[i] - '0';
	}

	int x, y;
	x = y = 0;
	FOR (i, 0, n)
	{
		if (A[i] == 1 && B[i] == 1) x++;
		if (A[i] == 0 && B[i] == 1) y++;
	}

	DP[0][0] = 1;
	FOR (i, 0, x+1)
	{
		FOR (j, 0, y+1)
		{
			if (i == 0 && j == 0) continue;
			LL cur = 0;
			if (j)
			{
				LL c = j * j;
				c *= DP[i][j-1];
				cur += c;
			}

			if (i && j)
			{
				LL c = j;
				c *= DP[i-1][j];
				cur += c;
			}

			DP[i][j] = cur % MOD;
		}
	}

	LL C = 1;
	LL C2 = 1;

	LL N = x + y;

	LL res = 0;
	FOR (i, 0, x+1)
	{
		LL cur = DP[x - i][y];
		cur*= F[x - i];
		cur %= MOD;
		cur *= F[i];
		cur %= MOD;
		cur *= F[i];
		cur %= MOD;
		cur *= C;
		cur %= MOD;
		cur *= C2;
		res = (res + cur) % MOD;

		C = (C * (N - i)) % MOD;
		C = (C * inv(i + 1)) % MOD;

		C2 = (C2 * (x - i)) % MOD;
		C2 = (C2 * inv(i+1)) % MOD;
	}

	cout<<res<<endl;


}
