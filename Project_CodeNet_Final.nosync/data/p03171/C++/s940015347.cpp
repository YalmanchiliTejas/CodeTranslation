#include<functional>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string.h>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
#include <queue>
#include<stack>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
int n;
vector<int> v;
ll dp[3001][3001][2];
ll calc(int i, int j, bool turn) {
	if (i > j)
		return 0;
	ll &ret = dp[i][j][turn];
	if (ret != -1)
		return ret;
	if (turn)
		ret = max(calc(i + 1, j, false) + v[i], calc(i, j - 1, false) + v[j]);
	else
		ret = min(calc(i + 1, j, true) - v[i], calc(i, j - 1, true) - v[j]);
	return ret;
}
int main() {
	//freopen("src.txt", "r", stdin);
	memset(dp, -1, sizeof dp);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout << calc(0, n - 1, true) << endl;
	return 0;
}