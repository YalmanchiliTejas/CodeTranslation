#include <iostream>
using namespace std;

int main() {
	int n;
	long long x;
	long long b[51], p[51],size[51];
	long long answer;

	cin >> n >> x;
		answer = 0;
		p[0] = 1;
		b[0] = 0;
		size[0] = 1;
		for (int i = 1; i <= n; i++) {
			p[i] = 1 + 2 * p[i - 1];
			b[i] = 2 + 2 * b[i - 1];
			size[i] = p[i] + b[i];
		}

		for (int k = n; k >= 0; k--) {
			if (k != 0) {
				if (x == size[k]) {
					answer += p[k];
					break;
				}
				if (x > size[k] / 2) {
					answer += p[k - 1] + 1;
					x -= (size[k] / 2) + 1;
				}
				else if (x == size[k] / 2) {
					answer += p[k - 1];
					break;
				}
				else {
					x -= 1;
				}
			}
			else if (x == 1) {
				answer += 1;
			}
		}

		cout << answer << endl;
}