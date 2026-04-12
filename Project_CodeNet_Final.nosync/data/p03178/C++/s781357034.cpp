#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int maxn = 10002;
const int maxd = 102;
const int mo = 1e9 + 7;

string K;

int n, D, f[maxn][maxd][2];

void add(int &a, int b) {
	a += b;
	a %= mo;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> K;
	cin >> D;

	n = K.length();
	reverse(K.begin(), K.end());

	int sum = 0;

	f[0][0][0] = f[0][0][1] = 1;
	for (int i = 1; i <= n; ++i) {
		int cur = K[i-1] - '0';
		sum += cur;

		for (int j = 0; j < D; ++j) {
			for (int t = 0; t <= 9; ++t) {
				add(f[i][(j+t)%D][0], f[i-1][j][0]);

				if (t < cur)
					add(f[i][(j+t)%D][1], f[i-1][j][0]);
				else
					if (t == cur)
						add(f[i][(j+t)%D][1], f[i-1][j][1]);
			}
		}
	}

	cout << (f[n][0][1]-1+mo)%mo << endl;

	return 0;
}