#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{
	int N;
	cin >> N;
	int a[110];
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	int max = 0;
	max = a[1];
	int num = 1;
	for (int i = 2; i <= N; i++)
	{
		if (a[i] >= max)
		{
			num++;
			max = a[i];
		}
	}
	cout << num << endl;
	//system("pause");
	return 0;
}