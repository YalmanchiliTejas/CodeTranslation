#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;
	char temp;
	temp = S[K - 1];

	for (int i = 0; i < N; i++) {
		if (S[i] != temp) {
			S[i] = '*';
		}
	}

	cout << S << endl;


	return 0;
}