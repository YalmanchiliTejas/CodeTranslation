#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <numeric>

#include <map>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <bitset>
#include <math.h>

#define INF 100100100

typedef long long int llint;

using namespace std;

typedef pair<int, int>Pii;

#define pi 3.141592653589793
#define mod 1000000007


int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int count = 0;
	while (true) {
		if (x >= y * (count + 1) + z * (count + 2))count++;
		else break;
	}
	cout << count << endl;
	return 0;
}