#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int x, y, z;
int main() {
	cin >> x >> y >> z;
	cout << (x - z) / (y + z) << endl;
}