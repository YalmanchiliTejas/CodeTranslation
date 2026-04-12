#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> P;

int main() {
	int n;

	while (cin >> n && n != 0) {
		P s[100010];
		int go, k = 1, ans = 0;

		for (int i = 1; i <= n; ++i) {
			cin >> go;

			if (i == 1) {
				s[k++] = P(i, go);
				continue;
			}

			if (s[k - 1].second != go) {
				if (i % 2) {//?\???°
					s[k++] = P(i, go);
				}
				else {
					if (k == 2)
						s[k - 1].second = go;
					else
						k--;
				}
			}
		}

		s[k] = P(n + 1, 0);
		for (int i = 1; i < k; ++i) {
			if (s[i].second == 0)
				ans += s[i + 1].first - s[i].first;
		}

		cout << ans << endl;
	}

	return 0;
}
/*
20
0
1
1
0
1
0
0
0
0
0
1
1
1
1
1
0
1
0
0
1
*/