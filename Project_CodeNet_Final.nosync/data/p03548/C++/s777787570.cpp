#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <functional>

#define REP(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
using ll = long long;


int main() {
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	cout << x / (y + z) << endl;
	return 0;
}