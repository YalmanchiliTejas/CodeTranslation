#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

char inp[10][10];
int ok[10][10];

int main()
{
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		cin >> inp[i];
	}
	ok[0][0] = 1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (inp[i][j] == '#' &&
					i + 1 < H && inp[i + 1][j] == '#' &&
					j + 1 < W && inp[i][j + 1] == '#'
			   ) {
				cout << "Impossible" << endl;
				return 0;
			} else if (inp[i][j] == '#' && !ok[i][j]) {
				cout << "Impossible" << endl;
				return 0;
			} else if (inp[i][j] == '#') {
				ok[i + 1][j] = 1;
				ok[i][j + 1] = 1;
			}
		}
	}
	cout << "Possible" << endl;
}
