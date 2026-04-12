#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
double r1, r2;
int main() {
	cin >> r1 >> r2;
	cout << fixed << setprecision(15) << 1.0 / (1.0 / r1 + 1.0 / r2) << endl;
	return 0;
}