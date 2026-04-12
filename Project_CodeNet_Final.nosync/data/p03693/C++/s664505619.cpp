#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if ((a * 100 + b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}