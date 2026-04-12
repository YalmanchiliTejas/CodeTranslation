#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
static const int MAX = 200000;

int main()
{
	int n;
	cin >> n;

	int m = 0;
	m = n / 15;
	cout << n * 800 - m * 200 << endl;

    return 0;
}