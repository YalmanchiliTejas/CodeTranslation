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
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0; i<n; ++i)
        cin >> x[i];

    vector<int> y = x;
    sort(y.begin(), y.end());

    for(int i=0; i<n; ++i){
        if(x[i] < y[n/2])
            cout << y[n/2] << endl;
        else
            cout << y[n/2-1] << endl;
    }

    return 0;
}
