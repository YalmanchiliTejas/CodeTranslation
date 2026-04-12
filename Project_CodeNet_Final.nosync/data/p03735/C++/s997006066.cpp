#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;
const int mod998 = 998244353;

int N;
ll x, y, X[2], Y[2], res, MIN, MAX;
pair<ll, ll>xy[200000];
int main() {
	cin >> N;
	X[0] = Y[0] = 0xE869120E869120;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		X[0] = min(X[0], x);
		X[1] = max(X[1], x);
		Y[0] = min(Y[0], y);
		Y[1] = max(Y[1], y);
		xy[i] = mkp(x, y);
	}
	res = (X[1] - X[0])*(Y[1] - Y[0]);
	sort(xy, xy + N);
	MIN = intmax;
	MAX = X[1];
	for (int i = 1; i < N; ++i) {
		MAX = max(MAX, xy[i - 1].second);
		MIN = min(MIN, xy[i - 1].second);
		res = min(res, (Y[1] - X[0])*(MAX - min(xy[i].first, MIN)));
	}
	cout << res << endl;
	return 0;
}