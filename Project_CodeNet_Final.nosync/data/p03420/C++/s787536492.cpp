#include<iostream>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long cnt = 0;
	if (k == 0) {
		cnt = n*n;
		cout << cnt << endl;
		return 0;
	}
	for (int b = k + 1; b <= n; b++) {
		int q, r;
		long long s;
		q = n / b;
		r = n % b;
		if (r < k) {
			s = q*(b - k);
		}
		else {
			s = (q + 1)*(r - k + 1) + q*(b - 1 - r);
		}
		//cout << s << endl;
		cnt += s;
	}
	cout << cnt << endl;
}