#include <bits/stdc++.h>

using namespace std;

static const int INF = 1e9 + 7;

template<typename T>
using Vec = vector<T>;

template<typename T, typename T2>
using P = pair<T, T2>;

template<typename... Args>
using Tup = tuple<Args...>;

template<typename T>
using qp = priority_queue<T, Vec<T>, greater<T> >;

template<typename T>
using pq = priority_queue<T>;

using llong = long long;
using ullong = unsigned long long;
using uint = unsigned int;

template<typename T>
T gcd(T x, T y)
{
	return y ? gcd(y, x % y) : x;
}

int h, w, k;

map<pair<int, int>, long long> dp;

long long dfs(int now, int x) {
	if (now == h) return x == k - 1;
	auto status = make_pair(now, x);
	if (dp.count(status)) return dp[status];
	long long res = 0;
	for (int i = 0; i < 1 << (w - 1); i++) {
		bool check = true;
		for (int j = 0; j < w - 2; j++) {
			if ((i >> j & 1) && (i >> (j + 1) & 1)) {
				check = false;
				break;
			}
		}
		if (check) {
			if (0 < x && (i >> (x - 1) & 1)) {
				res += dfs(now + 1, x - 1);
				res %= INF;
			}
			else if (x + 1 < w && ((i >> x) & 1)) {
				res += dfs(now + 1, x + 1);
				res %= INF;
			}
			else {
				res += dfs(now + 1, x);
				res %= INF;
			}
		}
	}
	return dp[status] = res;
}

void hawawa()
{
	int h, w;
	cin >> h >> w;
	string str;
	cin >> str;
	for (int i = 0; i + 1 < h; i++) {
		string next;
		cin >> next;
		int la, st;
		for (int i = w - 1; i >= 0; i--) {
			if (str[i] == '#') {
				la = i;
				break;
			}
		}
		for (int i = 0; i < w; i++) {
			if (next[i] == '#') {
				st = i;
				break;
			}
		}
		if (st < la) {
			cout << "Impossible\n";
			return;
		}
		str = next;
	}
	cout << "Possible\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
}
