#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	int N;
	cin >> N;

	int x, y;

	x = 800 * N;

	y = N / 15 * 200;

	cout << x - y << endl;

}