// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

#define MAXCHAR 255
#define ll unsigned long long

using namespace std;

ll funcComb(int n, int k) // nCk
{
	ll output = 1;
	for (int i = 0; i < k; i++)
	{
		output *= n - i;
	}
	for (int i = 0; i < k; i++)
	{
		output /= k - i;
	}

	return output;
}

ll calc(int log10N, int k)
{
	return funcComb(log10N, k) * pow(9, k);
}

int main()
{
	string N;	
	ll output = 0;
	int k;
	cin >> N >> k;
	int length = N.size();

	for (; k >= 0; k--)
	{
		if (N == string(length, '0') && k == 0)
		{
			output++;
			break;
		}
		int n = 0;
		for (int i = 0; i < length; i++)
		{
			if (N[i] != '0')
			{
				n = length - i-1;
				break;
			}
		}
		output += calc(n, k);
		int index = length - n - 1;
		int leftmostDigit = N[index]-'0';
		output += (leftmostDigit - 1) * calc(n, k - 1);
		N[index] = '0';
	}

	cout << output << endl;
	return 0;
}