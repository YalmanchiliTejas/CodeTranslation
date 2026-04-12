#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

int N;

bool ok(vector<int> &a) {
	for (int num : a) {
		if (num >= N) return false;
	}
	return true;
}

signed main() {
	cin >> N;

	vector<int> a;
	inputVector(a, N);

	int ret = 0;
	while (!ok(a)) {
		int cntall = 0;
		int cnt[50];
		memset(cnt, 0, sizeof cnt);
		rep(i, a.size()) {
			int dif = a[i] - N + 1;
			int tmp = (dif + N - 1) / N;
			cnt[i] = tmp;
			cntall += tmp;
			a[i] -= tmp * N;
		}
		rep(i, a.size()) {
			a[i] += cntall - cnt[i];
		}
		ret += cntall;
	}

	cout << ret << endl;

    return 0;
}
