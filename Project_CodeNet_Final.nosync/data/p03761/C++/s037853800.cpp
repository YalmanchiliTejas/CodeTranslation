#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int i,j,k;
	int array[n][26] = {0};

	for (i=0;i<n;i++)
	{
		string inp;
		cin >> inp;
		int size = inp.length();

		for (j=0;j<size;j++)
		{
			array[i][inp[j]-97] += 1;
		}
	}
	char chr = 'a';
	int min = 100;
	for (i=0;i<26;i++)
	{
		min = 100;
		for (j=0;j<n;j++)
		{
			if (array[j][i]<min)
				min = array[j][i];
		}
		for (k=0;k<min;k++)
		{
			cout << (char)(chr + i);
		}

	}

	return 0;
}