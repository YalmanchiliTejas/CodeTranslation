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

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int64_t seg_a[100000] = {};
int64_t seg_b[100000] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> ss(n);
	for (auto& s : ss) {
		cin >> s;
	}

	int64_t ans = 0;
	FOR_LT(c, 1, n) {
		int b = (n - 1) % c;
		if (b == 0) b = c;

		int64_t a_sum = 0;
		int64_t c_sum = 0;

		int l = 0;
		for (int i = 0; ; i++) {
			if (n <= (i + 1) * c + b) break;
			a_sum += ss[(i + 1) * c + b];
			c_sum += ss[i * c];
			l++;
		}

		int apos = b + c;
		int cpos = c * (l - 1);
		while (true) {
			bool skip = false;
			if (b == c) {
				if (apos <= cpos) {
					skip = true;
				}
			}

			if (!skip) {
				int64_t val = a_sum + c_sum;
				ans = max(ans, val);
			}

			if (cpos <= 0 || n <= apos) break;

			a_sum -= ss[apos];
			c_sum -= ss[cpos];
			apos += c;
			cpos -= c;
		}
	}

	cout << ans << endl;

	return 0;
}