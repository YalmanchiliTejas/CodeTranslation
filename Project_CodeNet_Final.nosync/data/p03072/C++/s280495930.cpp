#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

int n, m, ans = 1;
int h[30];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	m = h[0];

	for (int i = 1; i < n; i++) {
		if (m <= h[i]) {
			ans++;
			m = h[i];
		}
	}

	cout << ans << endl;

	return 0;
}
