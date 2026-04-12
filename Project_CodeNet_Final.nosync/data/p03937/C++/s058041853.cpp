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
    int h, w;
    cin >> h >> w;

    int cnt = 0;
    for(int i=0; i<h*w; ++i){
        char c;
        cin >> c;
        if(c == '#')
            ++ cnt;
    }

    if(cnt == h + w - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}