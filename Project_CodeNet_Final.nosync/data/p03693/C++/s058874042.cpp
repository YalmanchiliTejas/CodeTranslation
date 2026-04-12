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

	string a, b, c, x;
	int ans;
	cin >> a >> b >> c;
	
	x = a + b + c;
	ans = stoi(x);
	
	if (ans % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;

	}

}