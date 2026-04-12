#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long lnN;
	cin >> lnN;

	long lnWariCnt = lnN / 15;

	long lnTotal = lnN * 800 - lnWariCnt * 200;
	
	cout << lnTotal;
	return 0;
}
