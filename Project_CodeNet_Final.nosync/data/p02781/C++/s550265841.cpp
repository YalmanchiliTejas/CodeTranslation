#include "bits/stdc++.h"
using namespace std;

int main() {
	string N;
	long long K;
	cin >> N >> K;
	long long S = N.size();
	if (K == 1) {
		cout << (N[0] - '0') + (S - 1) * 9 << endl;
	}
	if (K == 2) {
		long long ANS = 0;
		string T;
		for (int i = 0; i < S; i++) {
			for (int j = i + 1; j < S; j++) {
				for (int k = 1; k <= 9; k++) {
					for (int l = 1; l <= 9; l++) {
						T = "";
						for (int m = 0; m < S; m++) {
							if (m == i) T += '0' + k;
							else if (m == j) T += '0' + l;
							else T += '0';
						}
						if (T <= N) ANS++;
					}
				}
			}
		}
		cout << ANS << endl;
	}
	if (K == 3) {
		long long ANS = 0;
		string T;
		for (int i = 1; i < S; i++) {
			for (int j = i + 1; j < S; j++) {
				for (int k = 1; k <= 9; k++) {
					for (int l = 1; l <= 9; l++) {
						T = N[0];
						for (int m = 1; m < S; m++) {
							if (m == i) T += '0' + k;
							else if (m == j) T += '0' + l;
							else T += '0';
						}
						if (T <= N) ANS++;
					}
				}
			}
		}
		cout << ANS + (N[0] - '0' - 1) * 81 * (S - 1) * (S - 2) / 2 + 729 * (S - 1) * (S - 2) * (S - 3) / 6 << endl;
	}
}