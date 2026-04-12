#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

long long int gcd(long long int x, long long int y)
{
	if (y == 0) { return x; }
	return gcd(y, x % y);
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	if (a == b) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }
	return 0;
}
