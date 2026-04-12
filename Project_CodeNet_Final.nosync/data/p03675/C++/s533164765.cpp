
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <unordered_map> //C++11
#include <queue>
#include <functional>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int b;
	int res[200003];
	for (int i = 0; i < 200003; i++) res[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (i % 2 == 0) {
			res[100000 + i / 2] = b;
		}
		else {
			res[100000 - (i + 1) / 2] = b;
		}
	}
	bool flag = false;
	if (n % 2 == 0) {
		for (int i = 0; i < 200003; i++) {
			if (res[i] >= 0) {
				if (!flag) {
					flag = true;
					cout << res[i];
				}
				else {

					cout << " " << res[i];
				}
			}
		}
		cout << endl;
	}
	else {
		for (int i = 200002; i >= 0; i--) {
			if (res[i] >= 0) {
				if (!flag) {
					flag = true;
					cout << res[i];
				}
				else {

					cout << " " << res[i];
				}
			}
		}
		cout << endl;
	}
	return 0;
}