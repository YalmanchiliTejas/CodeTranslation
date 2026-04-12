#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <map>

#define ll long long int
#define MAX 1000000

using namespace std;

int main(void)
{
	int n;
	int x, y;

	cin >> n;

	x = n * 800;

	y = n / 15 * 200;

	cout << x - y << endl;

	return (0);
}


