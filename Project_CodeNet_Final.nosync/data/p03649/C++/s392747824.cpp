#include <iostream>
using namespace std;

int n;
long long arr[50];

bool cando(long long num) {
	long long temp;
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		temp = arr[i] + num;
		ret += (temp + 1) / (n + 1);
	}
	return ret <= num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	bool zero = 1;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] >= n) zero = 0;
	}
	if (zero) {
		cout << 0;
		return 0;
	}

	long long low = 0, high = (long long)(1e18), mid;
	while (high - low > 1) {
		mid = (low + high) / 2;
		if (cando(mid)) high = mid;
		else low = mid;
	}
	long long ans = high;
	for (int i = 1; i <= 2500; ++i) {
		if (high - i >= 0 && cando(high - i)) ans = high - i;
	}
	cout << ans;
}