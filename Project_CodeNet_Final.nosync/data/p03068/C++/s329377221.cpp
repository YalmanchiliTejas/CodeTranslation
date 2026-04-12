#include <iostream>
using namespace std;
int main()
{
	int N,K;
	char S[10];
	cin >> N >> S >> K;
	char diff = S[K - 1];
	for (int i = 0; i < N; i++)
	{
		if (diff != S[i])
		{
			S[i] = '*';
		}
	}
	cout << S << endl;
		
	return 0;
}