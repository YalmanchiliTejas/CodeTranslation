#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool find(vector<int> v, int n) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == n) return true;
	}
	return false;
}

int main() {
	int a, b, p[100] = { 0 };
	vector<int> v;
	char t;
	while (cin >> a >> t >> b) {
		if (a == 0 && b == 0) break;
		p[a - 1] = b;
		if (!find(v, b)) v.push_back(b);
	}

	sort(v.begin(), v.end(), greater<int>());
	while (cin >> a) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == p[a - 1]) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}