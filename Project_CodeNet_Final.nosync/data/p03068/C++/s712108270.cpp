#include<iostream>

using namespace std;

int main()
{
	int N,K;
	string S;

	cin >> N >> S >> K;

	char check = S[K-1];

	for(int i=0;i<N;i++)
	{
		if(check != S[i])
		{
			S[i] = '*';
		}
	}

	cout << S << endl;

	return 0;
}