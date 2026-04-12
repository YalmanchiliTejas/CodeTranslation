#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

long long solve(long long k, long long a, long long b)
{    
    k -= a;
    if(k <= 0)
        return 1;
    else if(a <= b)
        return -1;
    else
        return 1 + (k + a - b - 1) / (a - b) * 2;
}

int main()
{
    long long k, a, b;
    cin >> k >> a >> b;

    cout << solve(k, a, b) << endl;

    return 0;
}
