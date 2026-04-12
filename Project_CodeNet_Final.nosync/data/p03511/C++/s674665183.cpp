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

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	string s, t, ans = "";
	int n = Read(), x = 0;
	cin >> s >> t;
	if (s + t > t + s)
		swap(s, t);
	for (int i = 1; i * s.length() <= n; i ++)
		if ((n - i * s.length()) % t.length() == 0)
			x = i;
	for (int i = 1; i <= x; i ++)
		ans += s;
	while (ans.length() ^ n)
		ans += t;
	cout << ans << endl;
	return 0;
}
