#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n;
	cin >> n;
	multiset<int> d;
	rep(i, n) {
		int a;
		cin >> a;
		auto it = d.lower_bound(a);
		if (it == d.begin()) {
			d.insert(a);
		} else {
			it--;
			d.erase(it);
			d.insert(a);
		}
	}
	cout << d.size() << endl;
}
