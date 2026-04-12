#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int main()
{
	int K, N;
	
	cin >> N;

	string S;
	cin >> S >> K;

	char kChar = S[K - 1];

	for (int i = 0; i < N; ++i)
	{
		if (S[i] != kChar)
		{
			S[i] = '*';
		}
	}

	cout << S << endl;

	return 0;
}