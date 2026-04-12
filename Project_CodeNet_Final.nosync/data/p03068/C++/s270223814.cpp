#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long llong;

int N, K;
char S[20];
char a;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	cin >> K;

	a = S[K - 1];
	for (int i = 0; i < N; i++)
	{
		if (S[i] == a)
		{
			cout << a;
		}

		else
		{
			cout << '*';
		}
	}
}