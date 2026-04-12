#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <random>

using namespace std; 

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int n = b * 10 + c;
	if (n % 4 == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}


	return 0;
}