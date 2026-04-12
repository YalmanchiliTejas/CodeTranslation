#include <bits/stdc++.h>

#define x first
#define y second
#define y1 Y1
#define y2 Y2
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

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

const int Maxn = 1e5 + 100;
const int Mod = 998244353;

int N, M, OP;

inline void Add (int &a, int b) { if ((a += b) >= Mod) a -= Mod; }

namespace BIT
{
	int sum[Maxn];
	inline void init () { for (int i = 1; i <= 10; ++i) sum[i] = 0; }
	inline void add (int x, int val) { for (; x < Maxn - 5; x += x & (-x)) sum[x] += val; }
	inline int query (int x) { int ans = 0; for (; x; x -= x & (-x)) ans += sum[x]; return ans; }
}

namespace Subtask1
{
	int A[Maxn], B[Maxn];
	int Max[Maxn];
	vector <int> P[Maxn];

	inline void main ()
	{
		for (int i = 1; i <= N; ++i) A[i] = read<int>(), P[A[i]].pb(i), Chkmax(Max[A[i]], i);
		for (int i = 1; i <= M; ++i) B[i] = read<int>();

		int ans = 1;
		for (int i = M; i >= 1; --i)
		{
			for (int j = 0; j < P[i + 1].size(); ++j) BIT :: add (P[i + 1][j], 1);
			if (B[i] == N + 1) continue;

			int pos = max(B[i], Max[i]);
			int sum = BIT :: query (N) - BIT :: query (pos - 1);
			sum = N - pos + 1 - sum;
			ans = (LL)ans * sum % Mod;
		}

		cout << ans << endl;
	}
}

namespace Subtask2
{
	int A[Maxn];
	int Max[Maxn], Min[Maxn];
	vector <int> P[Maxn];

	inline void main ()
	{
		for (int i = 1; i <= M; ++i) Min[i] = N + 1;
		for (int i = 1; i <= N; ++i) A[i] = read<int>(), P[A[i]].pb(i), Chkmax(Max[A[i]], i), Chkmin(Min[A[i]], i);

		int ans = 1;
		for (int i = M; i >= 1; --i)
		{
			for (int j = 0; j < P[i + 1].size(); ++j) BIT :: add (P[i + 1][j], 1);

			if (!Max[i])
			{
				LL sum = N - BIT :: query (N);
				sum = (sum * (sum + 1) / 2 + 1) % Mod;
				ans = (LL)ans * sum % Mod;
			}
			else
			{
				int up = Min[i], down = Max[i];

				int sum = up - BIT :: query (up);
				ans = (LL)ans * sum % Mod;

				sum = N - down + 1 - (BIT :: query (N) - BIT :: query (down - 1));
				ans = (LL)ans * sum % Mod;
			}
		}

		cout << ans << endl;
	}
}

namespace MATH
{
	const int Maxn = 9000 + 10;
	int fac[Maxn], ifac[Maxn];

	inline void Add (int &a, int b) { a += b; if (a >= Mod) a -= Mod; }
	inline void Add (int &a, LL b) { a += b; if (a >= Mod) a -= Mod; }

	inline int Pow (int a, int b)
	{
		int ans = 1;
		for (int i = b; i; i >>= 1, a = (LL)a * a % Mod) if (i & 1) ans = (LL)ans * a % Mod;
		return ans;
	}

	inline int Binom (int n, int m) { if (n < m) return 0; return (LL)fac[n] * ifac[m] % Mod * ifac[n - m] % Mod; }

	inline void math_init (int maxn)
	{
		fac[0] = 1;
		for (int i = 1; i <= maxn; ++i) fac[i] = (LL)fac[i - 1] * i % Mod;
		ifac[maxn] = Pow(fac[maxn], Mod - 2);
		for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	}
}

using namespace MATH;

namespace Poly
{
	const int Maxn = 9000 + 10;
	const int g = 3;
	int n, rev[Maxn << 1], wn[2][Maxn << 1];
	int F[Maxn << 1], G[Maxn << 1];

	inline void init ()
	{
		for (int i = 1; i < (Maxn << 1); i <<= 1) wn[0][i] = Pow (g, (Mod - 1) / (i << 1)), wn[1][i] = Pow(wn[0][i], Mod - 2);
	}

	inline void dft (int *A, int flag)
	{
		for (int i = 0; i < n; ++i) if (rev[i] < i) swap (A[i], A[rev[i]]);

		for (int mid = 1; mid < n; mid <<= 1)
		{
			int Wn = wn[flag][mid];
			for (int i = 0; i < n; i += (mid << 1))
			{
				int W = 1;
				for (int j = i; j < i + mid; ++j, W = (LL)W * Wn % Mod)
				{
					int x = A[j], y = (LL)W * A[j + mid] % Mod;
					A[j] = (x + y) % Mod, A[j + mid] = (x - y + Mod) % Mod;
				}
			}
		}

		int inv = Pow (n, Mod - 2);
		if (flag) for (int i = 0; i < n; ++i) A[i] = (LL)A[i] * inv % Mod;
	}

	inline void mul (int *A, int N, int *B, int M, int *C)
	{
		n = 1; while (n <= N + M) n <<= 1;
		for (int i = 0; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) + (i & 1 ? (n >> 1) : 0);

		for (int i = 0; i < n; ++i) F[i] = (i <= N) ? A[i] : 0;
		for (int i = 0; i < n; ++i) G[i] = (i <= M) ? B[i] : 0;

		dft (F, 0), dft (G, 0);
		for (int i = 0; i < n; ++i) F[i] = (LL)F[i] * G[i] % Mod;
		dft (F, 1);

		for (int i = 0; i <= N + M; ++i) C[i] = F[i];
	}
}

namespace Subtask3
{
	const int Maxn = 9000 + 100;

	int f[2][Maxn << 1], g[Maxn << 1];
	inline void main ()
	{
		Poly :: init ();
		math_init (9000);

		for (int i = 1; i <= N; ++i) g[i] = ifac[i + 2];
		f[0][0] = 1;

		int now = 0;
		for (int j = 1; j <= M; ++j)
		{
			now ^= 1;
			for (int i = 0; i <= N; ++i) f[now][i] = (LL)f[!now][i] * ifac[i] % Mod;
			Poly :: mul (f[now], N, g, N, f[now]);
			for (int i = 0; i <= N; ++i)
			{
				f[now][i] = (LL)f[now][i] * fac[i + 2] % Mod;
				Add (f[now][i], (LL)f[!now][i] * (1 + Binom (i + 1, 2)) % Mod);
			}
		}

		int ans = 0;
		for (int i = 0; i <= N; ++i) Add (ans, (LL)Binom (N, i) * f[now][i] % Mod);
		cout << ans << endl;
	}
}

inline void Solve ()
{
	Subtask3 :: main();
}

inline void Input ()
{
	N = read<int>(), M = read<int>();
}

int main()
{

	Input ();
	Solve ();

	return 0;
}
