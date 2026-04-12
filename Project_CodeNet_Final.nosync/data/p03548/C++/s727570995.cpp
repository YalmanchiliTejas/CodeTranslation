#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int  main()
{
	int x,y,z; cin >> x >> y >> z;

	if (x % (y+z) >= z)
		cout << x / (y+z);
	else
		cout << x / (y+z) - 1;
	return (0);
}
