#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	string S;

	cin >> N >> S >> K;
	K--;

	for (int i = 0; i < N; i++)
	{
		if (S[i] == S[K])
		{
			cout << S[i];
		}
		else
		{
			cout << '*';
		}
	}
	cout << endl;

	return 0;
}