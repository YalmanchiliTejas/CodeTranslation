#include <bits/stdc++.h>

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

const int Maxn = 1e4 + 100, Mod = 1e9 + 7;

int A[Maxn], D, N;
char S[Maxn];
int Dp[Maxn][100 + 10], Vis[Maxn][100 + 10];

inline void Add (int &a, int b) { a += b; if (a >= Mod) a -= Mod; }

inline int get_dp (int x, int sum, int limit)
{
	if (!limit && Vis[x][sum]) return Dp[x][sum];

	if (x == N + 1)
	{
		if (!sum) return 1;
		return 0;
	}

	int Max = limit ? A[x] : 9, ans = 0;
	for (int i = 0; i <= Max; ++i)
		Add (ans, get_dp (x + 1, (sum + i) % D, limit && i == Max));

	if (!limit) Dp[x][sum] = ans, Vis[x][sum] = 1;
	return ans;
}

inline void Solve ()
{
	printf("%d\n", (get_dp (1, 0, 1) - 1 + Mod) % Mod);
}

inline void Input ()
{
	scanf("%s", S + 1); D = read<int>();
	N = strlen(S + 1);
	for (int i = 1; i <= N; ++i) A[i] = S[i] - '0';
}

int main()
{
#ifdef hk_cnyali
	freopen("S.in", "r", stdin);
	freopen("S.out", "w", stdout);
#endif
	Input();
	Solve();
	return 0;
}
