#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	int K, i;
	cin >> K;
	for (i = 0; i < N; i++)
	{
		if (S[i] != S[K - 1])
			S[i] = '*';
	}
	cout << S;

	return 0;
}