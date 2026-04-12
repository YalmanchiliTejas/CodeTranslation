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

int main()
{
    vector<int> e(12);
    for(int i=0; i<12; ++i)
        cin >> e[i];

    sort(e.begin(), e.end());
    if(e[0] == e[3] && e[4] == e[7] && e[8] == e[11])
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}