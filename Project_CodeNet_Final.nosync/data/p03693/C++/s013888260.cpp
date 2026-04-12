#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;


void ABC064A()
{
	int r, g, b;
	cin >> r >> g >> b;
	int ret = r * 100 + g * 10 + b;
	if (ret % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
int main()
{
	ABC064A();
	return 0;
}