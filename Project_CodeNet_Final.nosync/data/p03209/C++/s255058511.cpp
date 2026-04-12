#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> numOfAll;
vector<long long> numOfP;

// nは層の数
long long getP(long long n, long long pos) {
	if (!n) return 1;
	if (pos < n) return 0;

	long long num = numOfAll[n];

	// all
	if (pos == num - 1) {
		return numOfP[n];
	}

	if (pos == num / 2) { // 中央
		return pow(2, n);
	}
	else if (pos < num / 2) { // 左半分
		return getP(n - 1, pos - 1);
	}
	else { // 右半分
		return numOfP[n - 1] + 1 + getP(n - 1, pos - num / 2 - 1);
	}
}


int main() {
	int n;
	long long x;
	cin >> n >> x; x--;

	numOfAll.push_back(1);
	for (int i = 1; i <= n; i++) {
		numOfAll.push_back(numOfAll[i-1] + pow(2, i + 1));
	}

	numOfP.push_back(1);
	for (int i = 1; i <= n; i++) {
		numOfP.push_back(numOfP[i - 1] + pow(2, i));
	}

	cout << getP(n, x) << endl;

	return 0;
}