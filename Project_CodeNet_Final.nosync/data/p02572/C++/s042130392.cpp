#include <bits/stdc++.h>
using namespace std;

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

typedef long long ll;

const int mod = 1e9 + 7;

int n;

int getint()
{
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

int main()
{
	n = getint();
	ll sum = 0, ans = 0;
	fo(i, 1, n)
	{
		ll x;
		x = getint();
		(ans += sum * x) %= mod;
		(sum += x) %= mod;
	}
	cout << ans << endl;
	return 0;
}
