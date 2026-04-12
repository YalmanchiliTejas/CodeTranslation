#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	string h;
	cin >> n;
	vector<int>v(26, 0);
	for (int i = 0; i < n; ++i) {
		cin >> h;
		vector<int>mon(26, 0);
		for (char H : h) {
			++mon[H - 'a'];
		}
		for (int j = 0; j < 26; ++j) {
			if (i == 0) v[j] = mon[j];
			else v[j] = min(v[j], mon[j]);
		}
	}

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < v[i]; ++j) {
			cout << (char)('a' + i);
		}
	}
	cout << endl;
}