#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((g * 10 + b) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}