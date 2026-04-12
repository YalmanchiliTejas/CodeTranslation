#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, m, s[55];
ll f(ll p, ll q) {
	ll md;
	if (p == -1 || q <= 0) return 0;
	md = s[p + 1] - 1;
	if (q < md) return f(p - 1, q - 1);
	else return f(p - 1, q - md) + s[p];
}
int main()
{
	ll i;
	cin >> n >>m;
	s[0] = 1;
	for (i = 1; i <= 51; i++) s[i] = s[i - 1] * 2;
	cout << f(n, m);
    return 0;
}
