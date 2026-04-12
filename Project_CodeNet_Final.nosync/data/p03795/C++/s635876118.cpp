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

#define INF 100100100

typedef long long int llint;

using namespace std;

typedef pair<int, int>Pii;

int main() {
	int n;
	cin >> n;
	cout << 800 * n - 200 * (n / 15) << endl;
	return 0;
}