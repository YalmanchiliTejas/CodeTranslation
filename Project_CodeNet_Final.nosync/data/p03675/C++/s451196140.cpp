#include<iostream>
using namespace std;

const int MAX = 200000;
int main() {
	int n, now, cng = -1;
	static int a[MAX];
	cin >> n;
	now = n / 2;
	if (n % 2) cng = 1;
	for (int i = 0;i < n;i ++) {
		cin >> a[now];
		now += cng;
		cng += cng > 0 ? 1 : -1;
		cng = -1 * cng;
	}
	cout << a[0];
	for (int i = 1;i < n;i ++) cout << ' ' << a[i];
	return 0;
}
// 1 2 3 4 5 6 7

// 1
// 2 1
// 3 1 2
// 4 2 1 3
// 5 3 1 2 4
// 6 4 2 1 3 5
// 7 5 3 1 2 4 6