#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string>

using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum;
	sum = 100 * a + 10 * b + c;
	if (sum % 4 == 0)
	{
		cout << "YES"<<endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
