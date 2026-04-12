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
	char X;
	char res;
	for (int i = 0; i < N; i++) {
		cin >> X;
		if (i == 0) {
			res = X;
		}
		else {
			if (res == 'T') {
				res = X;
			}
			else {
				res = 'T';
			}
		}

	}
	cout << res << endl;
}
