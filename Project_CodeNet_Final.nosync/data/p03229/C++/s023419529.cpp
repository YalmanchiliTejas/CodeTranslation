#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int n; cin >> n;
	vector<int64_t> as(n);
	for (auto& a : as) {
		cin >> a;
	}
	sort(as.begin(), as.end());

	int i = 0;
	int j = n - 2;
	int64_t ans = 0;
	int64_t m= 2;
	while (i <= j) {
		if (i == j) {
			ans += (m - 1) * (as[i + 1] - as[i]);
		}
		else {
			int64_t al = as[i + 1] - as[i];
			int64_t ah = as[j + 1] - as[j];
			ans += m * al + m * ah;
			if (i + 1 == j) {
				ans -= min(al, ah);
			}
		}
		i++;
		j--;
		m += 2;
	}
	cout << ans << endl;

	return 0;
}