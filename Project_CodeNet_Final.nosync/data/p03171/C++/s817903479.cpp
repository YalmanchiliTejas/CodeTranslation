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
#include <array>
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
#include <memory>
#include <regex>
using namespace std;

vector<int> a;
vector<vector<long long> > memo;

long long solve(int i, int j)
{
    if(j < i)
        return 0;
    if(memo[i][j] != -1)
        return memo[i][j];

    long long x = a[i] - solve(i+1, j);
    long long y = a[j] - solve(i, j-1);
    return memo[i][j] = max(x, y);
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    memo.assign(n, vector<long long>(n, -1));
    cout << solve(0, n-1) << endl;

    return 0;
}
