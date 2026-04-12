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
	int r, g, b;
	cin >> r >> g >> b;
	if ((r * 100 + g * 10 + b) % 4 == 0)puts("YES");
	else puts("NO");
	return 0;
}