#include<iostream>

using namespace std;

int main() {

	int N,K;
	char S[10];

	cin >> N >> S >> K;
	
	for (int i = 0; i < N; i++) {
		if (S[i] != S[K-1])
			S[i] = '*';
	}

	//output
	//for (int i = 0; i < N; i++)
	//	cout << S[i];
	cout << S;

	return 0;
}