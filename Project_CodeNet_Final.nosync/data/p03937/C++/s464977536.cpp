#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long INF = 1e9 + 7;
using namespace std;
typedef long long ll;
map<int, int> mp;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	int s = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == '#') s++;
		}
	}
	if (h + w - 1 == s) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}