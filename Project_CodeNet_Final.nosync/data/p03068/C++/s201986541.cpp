#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	char S[11];
	int N, K;
	cin >> N >> S >> K;
	for (int i = 0; i < N; i++)
	{
		if (S[i] != S[K-1])
		{
			S[i] = '*';
		}
	}
	cout << S;
	return 0;
}