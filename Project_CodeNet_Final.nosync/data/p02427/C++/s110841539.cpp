#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < (1 << n); i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))	v.push_back(j);
		}
		cout << i << ":";
		for (int k = 0; k < v.size(); k++) {
			cout << " " << v[k];
		}
		cout << endl;
	}
}
