#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<int, int> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };
int ans = 0;

void step(int num,int sum,int n,int m, vector<int> a, vector<int> b, vector<int> c) {

	c.at(num - 1) = 1;
	sum++;
	if (sum == n) {
		ans++;
	}
	rep(i, m) {
		if (num == a.at(i) && c.at(b.at(i) - 1) == 0) {
			step(b.at(i), sum, n, m, a, b, c);
			continue;
		}
		if (num == b.at(i) && c.at(a.at(i) - 1) == 0) {
			step(a.at(i), sum, n, m, a, b, c);
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	vector<int> c(n, 0);
	rep(i, m) cin >> a.at(i) >> b.at(i);
	
	int num = 1;
	int sum = 0;
	step(num, sum, n, m, a, b, c);

	cout << ans << endl;

	return 0;
}