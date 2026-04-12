#include <stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<cmath>
#include<algorithm>
#define LONG long long int
using namespace std;


int main() {
	LONG n, max,sum;
	max = 0;
	sum = 0;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp >= max)
		{
			sum++;
			max = tmp;
		}
	}
	cout << sum << endl;

	return 0;
}