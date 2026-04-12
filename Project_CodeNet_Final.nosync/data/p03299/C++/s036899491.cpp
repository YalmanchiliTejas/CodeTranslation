/*
PROG: agc26d
LANG: C++11
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>

using namespace std;

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 113

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int arr[MAXN];
int up[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN][2];
ll dp[MAXN][MAXN][MAXN][2];
ll ans;

ll getpow(ll a, ll e)
{
	if (e == 0)
	{
		return 1;
	}
	ll was = getpow(a, e / 2);
	if (e % 2)
	{
		return (was * was % INF * a % INF);
	}
	else
	{
		return (was * was % INF);
	}
}
ll solve(int L, int R, int idx, bool flag)
{
	//dp[L][R] given that we're at height arr[idx]
	if (L < 0 || R < 0 || L > R)
	{
		return 1;
	}
	if (vis[L][R][idx][flag])
	{
		return dp[L][R][idx][flag];
	}
	vis[L][R][idx][flag] = true;
	ll res = 0;
	//0 means no, 1 means yes
	int d = arr[up[L][R]] - arr[idx];
	if (flag)
	{
		//must alternate
		res += solve(L, up[L][R] - 1, up[L][R], 1) * solve(up[L][R] + 1, R, up[L][R], 1) % INF * getpow(2, d) % INF;
	}
	//MUST ALTERNATE!
	else
	{
		//must alternate
		res += solve(L, up[L][R] - 1, up[L][R], 1) * solve(up[L][R] + 1, R, up[L][R], 1) % INF * (getpow(2, d + 1) - 2) % INF;
		//mustnt alternate
		res += solve(L, up[L][R] - 1, up[L][R], 0) * solve(up[L][R] + 1, R, up[L][R], 0) * 2 % INF;
	}
	res %= INF;
	dp[L][R][idx][flag] = res;
//	cerr << "solve " << L << " " << R << " height " << arr[idx] << " flag " << flag << " ans "<< res << endl;
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("agc26d.in", "r"))
	{	
		freopen ("agc26d.in", "r", stdin);
		//	freopen ("agc26d.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i]--;
	}
	for (int i = 0; i < N; i++)
	{
		int mn = INF, idx = -1;
		for (int j = i; j < N; j++)
		{
			if (arr[j] < mn)
			{
				mn = arr[j]; idx = j;
			}
			up[i][j] = idx;
			//			cerr << up[i][j] << ' ';
		}
		//		cerr << endl;
	}
	arr[N] = 0;
	ans = solve(0, N - 1, N, 0);
	cout << ans << '\n';
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}
