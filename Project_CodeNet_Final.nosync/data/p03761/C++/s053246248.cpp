#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	string S[60];
	string ans = "";
	int N;

	cin >> N;

	int i;
	for (i = 0; i < N; i++) cin >> S[i];

	int small;
	for (char c = 'a'; c <= 'z'; c++) {
		small = 99;
		for (i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < S[i].length(); j++) {
				if (S[i][j] == c) {
					cnt++;
				}
			}
			small = min(small, cnt);
		}

		for (int t = 0; t < small; t++)		ans += c;
	}

	cout << ans << endl;

	return 0;
}