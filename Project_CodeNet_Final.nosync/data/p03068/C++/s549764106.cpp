#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, K;
	char S[10];

	cin >> N;
	cin >> S;
	cin >> K;

	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}

	cout << S << endl;
}