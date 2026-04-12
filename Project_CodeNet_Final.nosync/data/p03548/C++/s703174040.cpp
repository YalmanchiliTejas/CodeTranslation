#include <iostream>
#include <cstdlib>
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
	int x, y, z; cin >> x >> y >> z;
    cout << (x-z)/(y+z) << endl;
	return 0;
}