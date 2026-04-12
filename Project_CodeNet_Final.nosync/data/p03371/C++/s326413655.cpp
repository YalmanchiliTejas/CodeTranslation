#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <numeric>
#include <climits>
#include <functional>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
using ll = unsigned long long;
const ll mod = 1000000007;
const int M_MAX = 10000;
string al = "abcdefghijklmnopqrstuvwxyz";
//bool less_sec(const pair<int, int>&a, const pair<int, int>&b) {
//	return a.second > b.second;
//}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	ll sum = 0;
	ll minV = 1000000000;
	if (a + b >= 2 * c) {
		minV = (x >= y ? 2 * c*x : 2 * c*y);
		while (true) {
			sum += 2 * c;
			x--;
			y--;
			if (x == 0 || y == 0) break;
		}
		if (x == 0) sum += y * b;
		else sum += x * a;
		minV = min(minV, sum);
	}
	else {
		while (true) {
			sum += a + b;
			x--;
			y--;
			if (x == 0 || y == 0) break;
		}
		if(x == 0) sum += y * b;
		else sum += x * a;
		minV = min(minV, sum);
	}
	cout << minV << endl;
	return 0;
}