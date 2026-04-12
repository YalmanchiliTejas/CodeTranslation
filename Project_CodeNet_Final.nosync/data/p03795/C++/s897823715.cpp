
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, d=0;

	cin >> n;

	d = n / 15;

	cout << 800 * n - 200 * d << endl;

}