#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <regex>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define pq priority_queue
#define ll long long
#define MOD 1000000007
#define INF 9999999999
#define F first
#define S second

using namespace std;

typedef pair<int, int> pi;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

ll x, y, z, add, ans, A[1010101], Q[1010101];
int main() {
	cin >> x >> y >> z;
	add = z;
	while (1) {
		add += y;
		add += z;
		if (add <= x) {
			ans++;
		}
		else
			break;
	}
	cout << ans << endl;
	return 0;
}