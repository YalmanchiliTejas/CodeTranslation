// ABC_055_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0, i < (int)n; ++i)

int main()
{
	int n;
	cin >> n;

	if(n < 15) cout << 800 * n << "\n";
	else {
		int ans = 800 * n  - 200 * (n / 15);
		cout << ans << "\n";
	}

	return 0;
}