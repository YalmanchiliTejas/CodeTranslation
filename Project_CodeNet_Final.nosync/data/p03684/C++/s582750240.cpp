# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;

int main() {
	int n, x[100001], y[100001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	set < pair<int, int> >toA, toB;
	for (int i = 0; i < n; i++)toA.emplace(x[i], i);
	for (int i = 0; i < n; i++)toB.emplace(y[i], i);

	typedef pair<int, int> P;
	priority_queue<P, vector<P>, greater<P>>que;
	long long ret = 0;
	que.emplace(0, 0);
	bool used[100001] = {};
	while (!que.empty()) {
		int aa = que.top().first;
		int bb = que.top().second;
		que.pop();
		if (used[bb]++)continue;
		ret += aa;

		pair< int, int > qq(x[bb], bb);
		auto s = toA.lower_bound(qq);
		if (s != toA.begin()) que.emplace(x[bb] - prev(s)->first, prev(s)->second);
		++s;
		if (s != toA.end()) que.emplace(s->first - x[bb], s->second);

		qq.first = y[bb];
		auto s2 = toB.lower_bound(qq);
		if (s2 != toB.begin()) que.emplace(y[bb] - prev(s2)->first, prev(s2)->second);
		++s2;
		if (s2 != toB.end()) que.emplace(s2->first - y[bb], s2->second);
	}
	cout << ret << endl;
}