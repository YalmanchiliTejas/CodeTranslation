#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto&& x : a) cin >> x;
	deque<int> d;
	for (int i = 0; i < n; i++) {
		int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (p == 0) d.push_front(a[i]);
		else d[p - 1] = a[i];		
	}
	cout << d.size() << endl;

	return 0;
}