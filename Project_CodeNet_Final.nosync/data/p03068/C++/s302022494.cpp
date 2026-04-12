#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N = 0, K = 0;
	string S;
	char a;
	cin >> N>>S >> K;
	a = S[K-1];
	for (int i = 0; i < N; i++)
	{
		if (S[i] != a)
		{
			S[i] = '*';
		}
	}
	cout << S;
	return 0;
}