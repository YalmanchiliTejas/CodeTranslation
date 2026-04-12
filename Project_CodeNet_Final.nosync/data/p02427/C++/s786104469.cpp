#include <bits/stdc++.h>
using namespace std;

void print(bitset<20> b) {
	for (int i = 0; i < 20; i++) {
		if (b.test(i)) {
			cout << " " << i;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bitset<20> b1, b2;
	int n;

	cin >> n;
	int max = 1 << n;
	for (int i = 0; i < max; i++) {
		cout << i << ":";
		b2 = i;
		print(b2);
		cout << endl;
	}
}
