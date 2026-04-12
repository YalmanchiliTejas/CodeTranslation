#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int ans = 1;

	for (int i = 1; i < n; i++) {
		bool tmp = true;
		for (int j = 0; j < i; j++) {
			if (h[j] > h[i]) {
				tmp = false;
				break;
			}
		}
		if (tmp)ans++;
	}

	cout << ans << endl;

	return 0;
}