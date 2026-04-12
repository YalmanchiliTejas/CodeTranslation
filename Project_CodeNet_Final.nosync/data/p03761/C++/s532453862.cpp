#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, cnt[26];

int main() {
	cin >> N;
	for (int i = 0; i < 26; i++) cnt[i] = (1 << 30);
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < 26; j++) {
			int cnts = 0;
			for (int k = 0; k < S.size(); k++) { if ((S[k] - 'a') == j) cnts++; }
			cnt[j] = min(cnt[j], cnts);
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < cnt[i]; j++) cout << (char)('a' + i);
	}
	cout << endl;
	return 0;
}