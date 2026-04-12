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
    int x = 0;
    for(int i=0; i<3; ++i){
        int a;
        cin >> a;
        x *= 10;
        x += a;
    }

    if(x % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
