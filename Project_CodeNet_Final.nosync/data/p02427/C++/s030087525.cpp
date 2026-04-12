#include <bitset>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < pow(2.0, n); ++i) {
		bitset<18> a = i;
		cout << i << ':';
		for (int j = 0; j < 18; ++j) {
			if (a[j]) cout << ' ' << j;
		}
		cout << endl;
	}
}
