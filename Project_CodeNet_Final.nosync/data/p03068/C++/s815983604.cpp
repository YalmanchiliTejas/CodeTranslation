#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	long long N, K;
	string S;

	cin >> N >> S >> K;

	char s = S[K-1];
	for (int i = 0; i < N; i++) {
		if (S[i] != s) {
			S[i] = '*';
		}
	}
	cout << S << endl;
}