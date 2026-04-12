#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;
	for (char& i : S) {
		if (S[K - 1] != i) i = '*';
	}
	cout << S;
}