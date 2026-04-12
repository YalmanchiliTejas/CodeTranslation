#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) {
			break;
		}
		vector<int> player(m+1, 1);
		player[0] = 0;
		string b;
		int counter = 1;
		for (int i = 1; i <= n; i++) {
			cin >> b;
			int counter2 = 0;
			for (int j = 1; j <= m; j++) {
				if (player[j] == 1) {
					counter2++;
				}
			}
			if (counter2 == 1) {
				continue;
			}
			while (player[counter] != 1) {
				counter ++;
				if (counter > m) {
					counter = 1;
				}
			}
			if (i % 3 == 0 && i % 5 == 0) {
				if (b == "FizzBuzz") {
				} else {
					player[counter] = 0;
				}
			} else if (i % 3 == 0) {
				if (b == "Fizz") {
				} else {
					player[counter] = 0;
				}
			} else if (i % 5 == 0) {
				if (b == "Buzz") {
				} else {
					player[counter] = 0;
				}
			} else {
				bool hantei = true;
				int kazu = 0;
				for (int j = 0; j < b.size(); j++) {
					kazu *= 10;
					if (0 <= b[j]-'0' && b[j]-'0' <= 9) {
						kazu += b[j]-'0';
					} else {
						hantei = false;
						break;
					}
				}
				if (hantei) {
					if (i == kazu) {
					} else {
						player[counter] = 0;
					}
				} else {
					player[counter] = 0;
				}
			}
			counter++;
			if (counter > m) {
				counter = 1;
			}
		}
		int k;
		for (k = 1; k <= m; k++) {
			if (player[k] == 1) {
				cout << k;
				break;
			}
		}
		for (int j = k+1; j <= m; j++) {
			if (player[j] == 1) {
				cout << ' ' << j;
			}
		}
		cout << endl;
	}
	return 0;
}