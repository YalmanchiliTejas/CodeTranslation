#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	int r, g, b, sum;
	cin >> r >> g >> b;

	sum = r * 100 + g * 10 + b;
	if (sum % 4 == 0)
		cout << "YES";
	else
		cout << "NO";

	cout << endl;
	
	return 0;
}
