#include "iostream"
using namespace std;
int main() {
	int N, K;
	char S[10];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	cin >> K;
	K = K - 1;
	for (int i = 0; i < N; i++) {
		if (S[i] != S[K]) {
			S[i] = '*';
		}
	}
	for (int i = 0; i < N; i++) {
		cout << S[i];
	}
	cout << endl;
}