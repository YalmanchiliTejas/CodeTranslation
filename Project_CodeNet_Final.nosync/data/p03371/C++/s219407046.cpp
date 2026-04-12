#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = INF;
	rep(i, 2 * max(x, y) + 1) {
		ll cc = i * c;
		ll ac = 0;
		if (x - i/2 >= 0) {
			ac = (x - i/2) * a;
		}
		ll bc = 0;
		if (y - i/2 >= 0) {
			bc = (y - i/2) * b;
		}
		ans = min(ans, ac + bc + cc);
	}
	cout << ans << endl;
	system("pause");
}


