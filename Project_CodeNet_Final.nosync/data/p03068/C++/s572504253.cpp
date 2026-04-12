#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	string S;
	cin >> N >> S >> K; --K;
	for (int i = 0; i < N; i++) {
		cout << (S[i] == S[K] ? S[i] : '*');
	}
	cout << endl;
	return 0;
}
