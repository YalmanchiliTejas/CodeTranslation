#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

long long result, n,m,k;

long long total[2] = {};

long long a[100000] = {};

int main() {

	cin >> n >> k;
	
	result =0;

	for (int i = k+1; i <= n; i++) {
		result += (n / i)*(i - k);
		if (n%i >= k) {
			if (k != 0) {
				result += (n%i) - k + 1;
			}
			if (k == 0) {
				result += (n%i) - k;
			}

		}

	}


	cout << result << endl;

return 0;
}