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

inline LL Read()
{
	LL x = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	LL k = Read(), a = Read(), b = Read();
	if (a >= k)
		return puts("1"), 0;
	if (a <= b)
		return puts("-1"), 0;
	return printf("%lld\n", 2 * ((k - b - 1) / (a - b)) + 1), 0;
}
