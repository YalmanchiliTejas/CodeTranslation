#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#define rep0(i,n) for (int i = 0; i <= (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
using namespace std;
int main() {
	int n;
	int ans = 0;
	int count = 0;
	cin >> n;
	vector<int>r(n);
	rep0(i, n - 1) {
		cin >> r[i];
	}
	rep1(j, n - 1) {
		rep0(k, j - 1) {
			if (r[k] <= r[j])
				++count;
		}
		if (j == count)
			++ans;
		count = 0;
	}
	cout << ans + 1<< endl;
	return 0;
}