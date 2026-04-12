#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	for (int i = 1; i < N - 1; i++) {
		int l = 0;
		int r = N - 1;
		int sum = 0;
		for (; l < N - 1; l += i, r -= i) {
			sum += A[l];
			sum += A[r];
			if (r - i > 0 && (r % i != 0 || r > l)) {
				//cerr << r << " " << r - i << " " << sum << endl;
				res = max(res, sum);
				//cerr << sum << endl;
			}
		}
	}

	cout << res << endl;
}