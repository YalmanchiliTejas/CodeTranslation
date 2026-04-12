#include<iostream>

using namespace std;

int main() {
	int N;
	string S;
	int K;
	cin >> N >> S >> K;

	char ch = S[K - 1];
	for (int i = 0 ; i < N; i++) {
		if (ch == S[i]) {
			cout << S[i];
		}
		else {
			cout << "*";
		}
	}
	cout << endl;

}
