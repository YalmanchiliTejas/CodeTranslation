#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	ll x; cin >> x;
	vector<ll> p(52), l(52);
	p[0] = l[0] = 1;
	rep(i, 51)
	{
		p[i + 1] = 2 * p[i] + 1;
		l[i + 1] = 2 * l[i] + 3;
	}
	int now = n - 1;
	ll res = 0;
	while (now >= 0)
	{
		if (l[now] + 2 <= x)
		{
			res += p[now] + 1;
			x -= l[now] + 2;
		}
		else if (x > 0)--x;
		--now;
	}
	if (x)++res;
	cout << res << endl;
}
