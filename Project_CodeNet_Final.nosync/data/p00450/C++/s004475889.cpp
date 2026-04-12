#include<iostream>
using namespace std;
bool s[200000], x[200000];int n, S, v;
#pragma warning (disable:4996)
int main() {
	while (true) {
		cin >> n;
		if (!n) { break; }
		S = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &v);
			if (v == 0) { s[i] = false; }
			else { s[i] = true; }
		}
		for (int i = 0; i < n; i++) {
			x[i] = s[i];
			if (i % 2 == 1) {
				for (int j = i - 1; j >= 0; j--) {
					if (x[j] == s[i]) {
						break;
					}
					else {
						x[j] ^= true;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (x[i] == false) { S++; }
		}
		cout << S << endl;
	}
	return 0;
}