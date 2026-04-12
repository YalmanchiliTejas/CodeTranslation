#include <bits/stdc++.h>
#define int long long

#define x first
#define y second
#define y1 Y1
#define y2 Y2
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

inline void proc_status()
{
	ifstream t ("/proc/self/status");
	cerr << string (istreambuf_iterator <char> (t), istreambuf_iterator <char> ()) <<endl;
}

template <typename T> T read ()
{
	T sum = 0, fl = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
	return sum * fl;
}

const int Maxn = 3000 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int N, A[Maxn], Dp[Maxn][Maxn];

inline void Solve ()
{
	for (int i = 1; i <= N; ++i)
	{
		if (N & 1) Dp[i][i] = A[i];
		else Dp[i][i] = -A[i];
	}
	for (int l = 2; l <= N; ++l)
	{
		int flag;
		if ((N - l + 1) & 1) flag = 1;
		else flag = -1;

		for (int i = 1; i + l - 1 <= N; ++i)
		{
			int j = i + l - 1;
			if ((N - l + 1) & 1)
			{
				Dp[i][j] = -inf;
				Chkmax(Dp[i][j], Dp[i + 1][j] + flag * A[i]);
				Chkmax(Dp[i][j], Dp[i][j - 1] + flag * A[j]);
			}
			else
			{
				Dp[i][j] = inf;
				Chkmin(Dp[i][j], Dp[i + 1][j] + flag * A[i]);
				Chkmin(Dp[i][j], Dp[i][j - 1] + flag * A[j]);
			}
//			printf("%lld %lld %lld %lld\n", i, j, Dp[i][j], flag);
		}
	}
	cout<<Dp[1][N]<<endl;
}

inline void Input ()
{
	N = read<int>();
	for (int i = 1; i <= N; ++i) A[i] = read<int>();
}

main()
{
#ifdef hk_cnyali
	freopen("L.in", "r", stdin);
	freopen("L.out", "w", stdout);
#endif
	Input();
	Solve();
	return 0;
}