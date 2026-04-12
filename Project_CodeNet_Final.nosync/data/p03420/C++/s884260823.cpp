#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	ll r = 0;

	for (ll b = k + 1; b <= n; ++b)
	{
		r += (b - k) * (n / b);
		if (n % b >= k)
			r += n % b - k + (k ? 1 : 0);
	}

	cout << (r) << endl;

	return 0;
}
