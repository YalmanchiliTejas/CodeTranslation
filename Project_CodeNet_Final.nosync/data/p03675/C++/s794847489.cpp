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

signed main() {
	int n;
	cin >> n;

	vector<int> a;
	inputVector(a, n);

	deque<int> b;
	rep(i, n) {
		if (i % 2) b.push_front(a[i]);
		else b.push_back(a[i]);
	}

	if (n % 2) {
		reverse(all(b));
	}

	rep(i, n) {
		cout << b[i];
		if (i < n - 1) cout << ' ';
	}
	cout << endl;

    return 0;
}
