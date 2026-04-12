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
#include <cassert>
using namespace std;
typedef pair<int, int> P;

int n;
P p[200000];	//(val, pos)
int ans[200000];

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		int x; cin >> x;
		p[i] = P(x, i);
	}
	sort(p, p + n);
	
	//n / 2番かn / 2 - 1番がメジアン
	for (i = 0; i < n; i++) {
		if (i < n / 2) ans[p[i].second] = n / 2;
		else ans[p[i].second] = n / 2 - 1;
	}
	
	for (i = 0; i < n; i++) {
		cout << p[ans[i]].first << endl;
	}
	return 0;
}