#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_restaurant(void) {
	int n;
	cin >> n;

	int total = 800 * n;
	int y = 0;
	y = 200 * (n / 15);

	cout << total - y << endl;
}

int main()
{
    a_restaurant();
    return 0;
}