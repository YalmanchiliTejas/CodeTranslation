#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
using namespace std;

typedef int64_t ll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define vll vector<ll>
#define all(v) v.begin(), v.end()


int main() {
	ll H, W;
	cin >> H >> W;
	vector<string> a(H);
	rep(i, H) cin >> a[i];

	rep(i, H) {
		rep(j, W) {
			bool flag1 = false, flag2 = false;
			rep(k, H) if (a[k][j] == '#') flag1 = true;
			rep(k, W) if (a[i][k] == '#') flag2 = true;

			if (flag1 && flag2) {
				cout << a[i][j];
			}
			else if (flag2 == false) break;
			if (j == W - 1) cout << endl;
		}
		
	}
}
