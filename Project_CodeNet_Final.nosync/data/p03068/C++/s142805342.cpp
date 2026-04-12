#include <iostream>
#include <string>
using namespace std;

int N, K; string S;

int main() {
	cin >> N >> S >> K; K--;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != S[K]) S[i] = '*';
	}
	cout << S << endl;
	return 0;
}