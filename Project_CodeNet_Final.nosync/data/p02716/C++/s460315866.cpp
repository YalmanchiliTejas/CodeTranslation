#include<iostream>
#include<algorithm>
#include <string>
#include <cstring>
#include<climits>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
int n;
ll a[200001];
ll d[200001][3];
ll go(int x, int y) { // x까지 왔을 때 거를 수 있는 횟수가 y
	if (x >= n - y) {
		return 0;
	}
	ll &ret = d[x][y];
	if (ret != -1)return ret;
	ret = 0;
	ret = go(x + 2, y) + a[x];
	if (y > 0) {
		ret = max(ret, go(x + 1, y - 1));
		ret = max(ret, go(x + 3, y - 1) + a[x]);
	}
	if (y > 1) {
		ret = max(ret, go(x + 4, y - 2) + a[x]);
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	memset(d, -1, sizeof(d));
	if (n & 1) {
		cout << go(0, 2) << '\n';
	}
	else {
		cout << go(0, 1) << '\n';
	}


}