#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;
	for (char& i : S) {
		if (i != S[K - 1]) i = '*';
	}
	cout << S;
}