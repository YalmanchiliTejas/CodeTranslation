#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string N;
	int K;
	cin >> N >> K;
	int L = N.length();
	if (L < K) {
		cout << 0 << endl;
		return 0;
	}
	string A(L, '0');
	int ans = 0;
	switch (K) {
	case 1:
		for (int i = 0; i < L; i++) {
			A = string(L, '0');
			for (char a = '1'; a <= '9'; a++) {
				A[i] = a;
				if (A <= N) ans++;
			}
		}
		break;
	case 2:
		for (int j = 1; j < L; j++) {
			for (char a = '1'; a <= '9'; a++) {
				A[0] = a;
				for (char b = '1'; b <= '9'; b++) {
					A[j] = b;
					if (A <= N) ans++;
					A[j] = '0';
				}
			}
		}
		ans += (L - 1) * (L - 2) / 2 * 9 * 9;
		break;
	case 3:
		for (int j = 1; j < L; j++) {
			for (int k = j + 1; k < L; k++) {
				for (char a = '1'; a <= '9'; a++) {
					A[0] = a;
					for (char b = '1'; b <= '9'; b++) {
						A[j] = b;
						for (char c = '1'; c <= '9'; c++) {
							A[k] = c;
							if (A <= N) ans++;
							A[k] = '0';
						}
						A[j] = '0';
					}
				}
			}
		}
		ans += (L - 1) * (L - 2) * (L - 3) / 6 * 9 * 9 * 9;
	}
	cout << ans << endl;
}