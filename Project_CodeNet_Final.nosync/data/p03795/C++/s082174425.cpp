#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


int main()
{
	int n,x,y;
	cin >> n;
	x = 800 * n;
	y = (n / 15) * 200;
	cout << x - y << endl;

	return 0;
}