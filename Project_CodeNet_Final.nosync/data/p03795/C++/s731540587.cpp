#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   

using namespace std;


int main() {

	int a, y;
	int ans = 0;

	cin >> a;
	
	ans = a * 800;

	y = a / 15;

	cout << ans - 200 * y << endl;
	
}

