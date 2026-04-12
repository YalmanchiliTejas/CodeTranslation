#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 205;

vector <int> ans;
int n, a[MAXN];

inline void Solve(int x)
{
	ans.pb(x);
	for (int i = x; i < n; i ++)
		swap(a[i], a[i - x]);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 0; i < n; i ++)
		a[i] = Read();
	while (!is_sorted(a, a + n))
		if (a[0] && a[0] < a[n - 1])
			Solve(n - 1);
		else
			Solve(1);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++)
		printf("%d\n", ans[i]);
	return 0;
}
