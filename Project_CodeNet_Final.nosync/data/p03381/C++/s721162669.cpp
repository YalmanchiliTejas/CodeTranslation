#include"bits/stdc++.h"
using namespace std;

int n;

vector<pair<int, int> > v;
int ich(int cur, int er) {
	if (cur >= er) {
		cur--;
	}
	return cur;
}
int ans[200002];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	int p = v.size() / 2;
	int sz = v.size() - 1;
	sz /= 2;
	for (int i = 0; i < v.size(); i++) {
		int b = p;
		while (ich(b, i) != sz) {
			if (ich(b, i) < sz) {
				b++;
			}
			else {
				b--;
			}
		}
		if (b == i) {
			if (ich(b - 1, i) == sz) {
				b--;
			}
			else {
				b++;
			}
		}
		ans[v[i].second] = v[b].first;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}