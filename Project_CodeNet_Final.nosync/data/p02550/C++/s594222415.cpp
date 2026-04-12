#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, x, m, i, j, k, ans, c, ct, a, ss;
	cin >> n >> x >> m;
	vector<long long> last(m, -1), s(m);

	ans = 0;
	ss = 0;
	for (i = 1; i <= n; i++) {
		if (i == 1) a = x;
		else a = (a * a) % m;
		ss += a;

		if (last[a] == -1) {
			last[a] = i;
			ans += a;
			s[a] = ss;
		}
		else {
			c = i - last[a];
			ct = (n - last[a]) / c;
			
			ans = s[a] + ct * (ss - s[a]);
			i = last[a] + ct * c;

			for (j = i + 1; j <= n; j++) {
				a = (a * a) % m;
				ans += a;
			}
			break;
		}
	}

	cout << ans << "\n";


	return 0;
}


