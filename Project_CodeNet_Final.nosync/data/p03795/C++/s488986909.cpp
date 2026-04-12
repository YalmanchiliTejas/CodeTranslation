#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	int x, y;
	x = N * 800;
	y = N / 15 * 200;
	cout << x - y << endl;
	return 0;
}