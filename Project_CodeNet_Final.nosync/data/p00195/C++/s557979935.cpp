#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int a[5] = {};
	int aa[5] = {};
	string s[5] = { "A","B","C","D","E" };
	int b, c;
	while (cin >> b >> c, b, c) {
		int d, e;
		a[0] = b + c;
		aa[0] = a[0];
		for (int i = 0; i < 4; i++) {
			cin >> d >> e;
			a[i + 1] = d + e;
			aa[i + 1] = a[i + 1];
		}
		sort(aa, aa + 5);

		for (int i = 0; i < 5; i++) {
			if (a[i] == aa[4]) {
				cout << s[i] << ' '<<a[i]<<endl;
				break;
			}
		}

	}
	return 0;
}