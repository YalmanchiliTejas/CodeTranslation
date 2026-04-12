#include "bits/stdc++.h"
using namespace std;

int main(void) {
	
	int N, K;
	string S;

	cin >> N >> S >> K;

	char k = S.at(K - 1);

	for (int i = 0; i < N; i++)
	{
		if (S.at(i) != k) S.at(i) = '*';
	}

	cout << S << endl;

	
	return 0;
}