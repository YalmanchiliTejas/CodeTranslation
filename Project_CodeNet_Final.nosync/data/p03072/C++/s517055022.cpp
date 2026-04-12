#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int h[20];

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> h[i];
	
	int ma = 0, cnt = 0;
	for (i = 0; i < n; i++) {
		if (ma <= h[i]) cnt++;
		ma = max(ma, h[i]);
	}
	cout << cnt << endl;
	return 0;
}