#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N;
	char A[100];
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	cin >> K;

	for (int i = 1; i <= N; i++)
	{
		if (A[i] != A[K])
		{
			A[i] = '*';
		}
	}
	for (int i = 1; i <= N; i++)
	{
		
		cout << A[i];
	}

	// system("pause");
	return 0;
}