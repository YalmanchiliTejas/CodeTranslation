#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>
using namespace std;

namespace {

}

int main()
{
	int r = 0, g = 0, b = 0;

	cin >> r >> g >> b;

	int num = r * 100 + g * 10 + b;

	if (num % 4 == 0){
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;


	return 0;
}