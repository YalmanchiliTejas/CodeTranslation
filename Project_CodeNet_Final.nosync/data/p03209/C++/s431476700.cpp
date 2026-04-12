// D.

#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL pat[51] = { 1 };
LL len[51] = { 1 };

LL patties(LL level, LL e) {
	if (level <= 0) {
		return e > 0;
	}
	--e;
	LL tot = 0;
	if (e > len[level - 1]) {
		tot = pat[level - 1];
		e -= len[level - 1];
		if (e > 0) {
			--e;
			++tot;
		}
	}
	return tot + patties(level - 1, e);
}

int main(int argc, char *argv[])
{
	for (int i = 1; i <= 50; ++i) {
		pat[i] = pat[i - 1] * 2 + 1;
		len[i] = len[i - 1] * 2 + 3;
	}
	LL n, x;
	cin >> n >> x;
	LL ans = patties(n, x);
	cout << ans << endl;
	return 0;
}
