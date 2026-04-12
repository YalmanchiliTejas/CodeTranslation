#include <iostream>
using namespace std;
const int MAX = 53;

long long pow2[MAX] = {1};

long long size(long long n) {
	return pow2[n+2] - 3;
}

long long f(long long n, long long x) {
	if (n == 0) return 1;
	if (x == 1) return 0;
	x--;
	if (x <= size(n-1)) return f(n-1, x);
	x -= size(n-1);
	if (x == 1) return pow2[n];
	x--;
	if (x <= size(n-1)) return pow2[n] + f(n-1, x);
	return 2 * (pow2[n]-1) + 1;
}

int main() {
	for (int i = 1; i < MAX; i++) pow2[i] = 2 * pow2[i-1];
	long long n, x;
	cin >> n >> x;
	long long ans = f(n, x);
	cout << ans << endl;
	return 0;
}