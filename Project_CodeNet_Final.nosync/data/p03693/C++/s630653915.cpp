#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int g, b;
	cin >> g >> g >> b;
	cout << ((g * 10 + b) % 4 == 0 ? "YES" : "NO");
}
