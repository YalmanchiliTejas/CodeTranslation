#include<iostream>
#include<vector>
#include <unordered_map>  
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <float.h>
using namespace std;


int main() {
	int x, y, z, count;
	cin >> x >> y >> z;
	count = (x - z) / (y + z);
	cout << count << endl;
	return 0;
}
