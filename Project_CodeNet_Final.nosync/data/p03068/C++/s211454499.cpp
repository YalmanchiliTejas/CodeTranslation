#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N;
	cin >> S;
	cin >> K;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] != S[K - 1]) {
			S.replace(i, 1, 1, '*');
		}
	}
	cout << S << endl;
}