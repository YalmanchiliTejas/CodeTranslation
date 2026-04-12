#include <bits/stdc++.h>

#define x first
#define y second
#define y1 Y1
#define y2 Y2
#define mp make_pair
#define pb push_back
#define DEBUG(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <LL, int> pli;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline T read ()
{
	T sum = 0, fl = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
	return sum * fl;
}

inline void proc_status ()
{
	ifstream t ("/proc/self/status");
	cerr << string (istreambuf_iterator <char> (t), istreambuf_iterator <char> ()) << endl;
}

const int Maxn = 1e5 + 100, Maxm = 2e5 + 100;
const LL inf = 1e18;
const int Mod = 1e9 + 7;

int N, M;
int S, T;
int e, Begin[Maxn], To[Maxm << 1], Next[Maxm << 1], W[Maxm << 1];

inline void add_edge (int x, int y, int z) { To[++e] = y; Next[e] = Begin[x]; Begin[x] = e; W[e] = z; }

inline void Add (int &a, int b) { if ((a += b) >= Mod) a-= Mod; }

struct Graph
{
	LL Dis[Maxn];
	int Num[Maxn], Vis[Maxn];
	priority_queue <pli, vector <pli>, greater <pli> > Q;

	inline void dij (int s)
	{
		for (int i = 1; i <= N; ++i) Dis[i] = inf, Num[i] = 0;

		Q.push (mp (0, s));
		Dis[s] = 0, Num[s] = 1;

		while (!Q.empty())
		{
			int x = Q.top().y; Q.pop();
			if (Vis[x]) continue;
			Vis[x] = 1;
			for (int i = Begin[x]; i; i = Next[i])
			{
				int y = To[i];
				if (Chkmin (Dis[y], Dis[x] + W[i])) Num[y] = Num[x], Q.push (mp (Dis[y], y));
				else if (Dis[y] == Dis[x] + W[i]) Add (Num[y], Num[x]);
			}
		}
	}
} G[2];

inline int sqr (int x) { return (LL) x * x % Mod; }

inline void Solve ()
{
	G[0].dij (S), G[1].dij (T);

	LL dist = G[0].Dis[T];
	int ans = sqr (G[0].Num[T]);

	for (int i = 1; i <= N; ++i)
	{
		LL d0 = G[0].Dis[i], d1 = G[1].Dis[i];
		int g0 = G[0].Num[i], g1 = G[1].Num[i];

		if ((d0 == d1) && (d0 + d1 == dist)) 
			Add (ans, Mod - sqr ((LL) g0 * g1 % Mod));
	}

	for (int x = 1; x <= N; ++x)
		for (int i = Begin[x]; i; i = Next[i])
		{
			int y = To[i];
			LL d0 = G[0].Dis[x], d1 = G[1].Dis[y], d = W[i];
			int g0 = G[0].Num[x], g1 = G[1].Num[y];

			if ((d0 + d + d1 == dist) && (d0 + d > d1) && (d1 + d > d0))
				Add (ans, Mod - sqr ((LL) g0 * g1 % Mod));
		}

	cout << ans << endl;
}

inline void Input ()
{
	N = read<int>(), M = read<int>();
	S = read<int>(), T = read<int>();
	for (int i = 1; i <= M; ++i)
	{
		int x = read<int>(), y = read<int>(), z = read<int>();
		add_edge (x, y, z);
		add_edge (y, x, z);
	}
}

int main()
{

#ifdef hk_cnyali
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
#endif

	Input ();
	Solve ();

	return 0;
}
