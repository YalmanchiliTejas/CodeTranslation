#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	cout << (800 * N) - ((N / 15) * 200) << endl;
	
	return 0;
}
