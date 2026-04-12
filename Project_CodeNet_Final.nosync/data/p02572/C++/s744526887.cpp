//#pragma GCC optimize("trapv")
#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <functional>
#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;

void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

signed main()
{
	fast();
	int n;
	cin >> n;
	vector <int> a(n);
	int sum = 0;
	for (long long & e : a)
	{
		cin >> e;
		sum += e;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		sum -= a[i];
		ans = (ans + (((sum % MOD) * a[i]) % MOD)) % MOD;
	}
	cout << ans << '\n';
	return 0;
}