#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a -= c;
	cout << a / (b + c) << endl;
	return 0;
}
