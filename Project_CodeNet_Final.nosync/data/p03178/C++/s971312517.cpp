#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

const int mod = 1e9 + 7;
 
inline int add(int x, int y)
{
	if (x + y >= mod)
		return x + y - mod;
	return x + y;
}
 
inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

inline int power(int x, int y)
{
	int r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}
	
	return r;
}

const int D = 107;
const int N = 10007;

int dp[N][D];

string s;
int d;

int f(int x, int rem)
{
	rem %= d;
	if (x == 0)
		return rem == 0;
	
	if (dp[x][rem] != -1)
		return dp[x][rem];

	if (x == 1)
	{
		dp[x][rem] = 0;
		FOR(i, 0, 10)
			if (i % d == rem)
				++dp[x][rem];
		return dp[x][rem];
	}
	
	int res = 0;
	FOR(i, 0, 10)
	{
		int bude = (((rem - i) % d) + d) % d;
		res = add(res, f(x - 1, bude));
	}
	
	return dp[x][rem] = res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	FILL(dp, -1);
	cin >> s >> d;
	int n = SZ(s);

	int ans = 0;
	int je = 0;
	FOR(i, 0, n)
	{
		int treba = (d - je) % d;
		FOR(j, 0, s[i] - '0')
		{
			ans = add(ans, f(n - i - 1, treba));
			--treba;
			if (treba < 0)
				treba += d;
		}
		
		je += s[i] - '0';
		je %= d;
	}

	if (je)
		ans = add(ans, mod - 1);
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
