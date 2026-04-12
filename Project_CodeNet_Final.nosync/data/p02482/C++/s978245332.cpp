#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if(a < b)
		cout << "a < b";
	else if(a > b)
		cout << "a > b";
	else
		cout << "a == b";

	cout << endl;
	return 0;
}