#include<iostream>
using namespace std;
int main() {
	int ms, mn;
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0)break;
		ms = 0;
		mn = a + b;
		for (int i = 1; i <= 4; ++i) {
			cin >> a >> b;
			int num = a + b;
			if (mn < num) {
				ms = i;
				mn = num;
			}
		}
		cout << (char)('A' + ms) << ' ' << mn << endl;
	}
	return 0;
}