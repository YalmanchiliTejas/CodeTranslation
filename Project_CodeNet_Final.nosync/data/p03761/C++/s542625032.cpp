#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>

#define INF 1000000000000000000
using namespace std;
typedef long long ll;


int main() {
	int n;
	int cn[30] = {};
	string str;
	cin >> n;
	for (int i = 'z' - 'a'; i >= 0; i--) {
		cn[i] = 100;
	}
	for (int i = 0; i < n; i++) {
		cin >> str;
		int temp[30] = {};
		for (auto &&c : str) {
			temp[c - 'a']++;
		}
		for (int i = 'z' - 'a'; i >= 0; i--) {
			cn[i] = min(cn[i], temp[i]);
		}
	}
	for (int i = 0; i <= 'z' - 'a'; i++) {
		char c = (char)('a' + i);
		for (int j = 0; j < cn[i]; j++) {
			cout << c;
		}
	}
	cout << endl;
	return 0;
}