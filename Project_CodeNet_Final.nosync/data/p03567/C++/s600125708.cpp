#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
		char A[1000];
		int i,k=0;
		cin >> A;
		for (i = 0; i < 5; i++)
		{
			if ((A[i] == 65) && (A[i+1] == 67))
			{
				k = 1;
				break;
			}
		}
		if (k == 1)
			printf("Yes");
		if (k == 0)
			printf("No");
	return 0;
}