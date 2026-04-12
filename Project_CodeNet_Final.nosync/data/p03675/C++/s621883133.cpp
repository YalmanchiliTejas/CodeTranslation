#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> u, v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i % 2) {
			v.push_back(a);
		} else {
			u.push_back(a);
		}
	}
	if (n % 2) {
		for (int i = u.size() - 1; i >= 0; i--) {
			cout << u[i] << ' ';
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
	} else {
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << ' ';
		}
		for (int i = 0; i < u.size(); i++) {
			cout << u[i] << ' ';
		}
	}
	return 0;
}
