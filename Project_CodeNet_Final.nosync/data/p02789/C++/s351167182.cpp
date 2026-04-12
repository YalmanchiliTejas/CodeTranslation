#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second



int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a == b)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}
