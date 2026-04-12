#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>

using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Graph = vector<vector<int> >;

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;


int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int t = 0;
	if (a + b >= 2 * c) {
		if (x > y) {
			t += y * 2 * c;
			if (a >= 2 * c) t += 2 * c * (x - y);
			else  t += a * (x - y);
		}
		else {
			t += x * 2 * c;
			if (b >= 2 * c)  t += 2 * c * (y - x);
			else  t += b * (y - x);
		}
	}
	else {
		t += a * x + b * y;
	}
	cout << t << endl;
}
