#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <ios> 
#include <iomanip>
using namespace std;

#define N_MAX   (100000)
#define LL_MAX_NUM (1LL<<60)
#define INF 1e7

typedef long long ll;
typedef long long int lli;

int main() {
	int r,g, b;
	cin >> r >> g >> b;
	string res;
	if ((100 * r + 10 * g + b) % 4 == 0) {
		res = "YES";
	}
	else {
		res = "NO";
	}
	cout << res << endl;
	return 0;
}