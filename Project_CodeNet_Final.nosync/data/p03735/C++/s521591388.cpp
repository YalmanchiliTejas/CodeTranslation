#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

template<typename T> void Chkmax(T &x, const T &y) { x = x > y ? x : y; }
template<typename T> void Chkmin(T &x, const T &y) { x = x < y ? x : y; }

namespace io
{
	const int maxb = 1 << 15;
	char b[maxb], *s = b, *t = b;
	bool Getchar(char &ch)
	{
		return ch = s == t && (t = (s = b) + fread(b, 1, maxb, stdin)) == b ? 0 : *s ++;
	}
}

int Getint()
{
	using namespace io;
	char ch;
	while (Getchar(ch) && (ch < '0' || ch > '9'));
	int s = ch - '0';
	while (Getchar(ch) && ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0';
	return s;
}

const int maxn = 2e5 + 10;

struct Node
{
	int x, y;
	Node() {}
	Node(int x, int y) : x(min(x, y)), y(max(x, y)) {}
	bool operator < (const Node &a) const { return x < a.x; }
} a[maxn];

int main()
{
	int n = Getint();
	for (int i = 0; i < n; ++ i)
		a[i] = Node(Getint(), Getint());
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	sort(a, a + n);
	int Mx = 0, posMx;
	for (int i = 0; i < n; ++ i)
		if (a[i].y >= Mx)
		{
			Mx = a[i].y;
			posMx = i;
		}
	int Rmax = Mx, Rmin = a[0].y, Bmax = a[posMx].x, Bmin = a[0].x;
	for (int i = 1; i < n; ++ i)
	{
		if (i == posMx) continue;
		Chkmin(Rmin, a[i].y);
		Chkmax(Bmax, a[i].x);
	}
	LL ans = 1ll * (Rmax - Rmin) * (Bmax - Bmin);
	if (!posMx)
	{
		printf("%lld\n", ans);
		return 0;
	}
	Rmax = Mx, Rmin = a[0].x, Bmax = max(max(a[0].y, a[posMx].x), a[n - 1].x), Bmin = min(min(a[0].y, a[posMx].x), a[1].x);
	Chkmin(ans, 1ll * (Rmax - Rmin) * (Bmax - Bmin));
	int preMn = a[0].y;
	a[n].y = Mx;
	for (int i = 1; i < n; ++ i)
	{
		if (i == posMx)
		{
			Chkmin(preMn, a[i].x);
			continue;
		}
		Chkmin(preMn, a[i].y);
		Chkmax(Bmax, a[i].y);
		Bmin = min(preMn, a[i + 1].x);
		Chkmin(ans, 1ll * (Rmax - Rmin) * (Bmax - Bmin));
	}
	printf("%lld\n", ans);
	return 0;
}
