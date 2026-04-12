#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	long long** maxsum = new long long* [n];

	for (int i = 0;i < n;i++) {
		cin >> a[i];
		maxsum[i] = new long long[3];
	}
	maxsum[0][0] = maxsum[0][1] = 0;
	maxsum[0][2] = a[0];
	maxsum[1][0] = 0;
	maxsum[1][1] = maxsum[1][2] = (long long)max(a[0], a[1]);
	for (int i = 2;i < n;i++) {
		if (i % 2 == 0) {
			maxsum[i][0] = maxsum[i][1] = max(maxsum[i - 1][1], maxsum[i - 2][0] + a[i]);
			maxsum[i][2] = maxsum[i - 2][2] + a[i];
		}
		else {
			maxsum[i][0] = max(maxsum[i - 1][0], maxsum[i - 2][0] + a[i]);
			maxsum[i][1] = maxsum[i][2] = max(maxsum[i - 1][2], maxsum[i - 2][2] + a[i]);
		}
	}
	cout << maxsum[n - 1][1] << "\n";
}


