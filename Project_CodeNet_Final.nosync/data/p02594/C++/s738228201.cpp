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
#define ll long long

using namespace std;
const ll dividend = 1000000007;
const ll limit = pow(10, 18);
const ll bigNum = pow(10, 9);

ll funcComb(int n, int k) 
{
	ll output = 1;
	int sum = n + k;
	vector<int> dividends;
	for (int i = 0; i < k; i++)
	{
		dividends.push_back(k - i);
	}
	for (int i = 0; i < k; i++)
	{
		output *= sum - i;
		for (auto it = dividends.begin(); it != dividends.end(); it++)
		{
			if (*it == 0)
				continue;
			if (output % *it == 0)
			{
				output /= *it;
				*it = 0;
			}
		}
		if (output > dividend)
		{
			output %= dividend;
		}
	}

	return output;
}

vector<bool> outputs;

int main()
{
	int x;
	cin >> x;
	if (x >= 30)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}