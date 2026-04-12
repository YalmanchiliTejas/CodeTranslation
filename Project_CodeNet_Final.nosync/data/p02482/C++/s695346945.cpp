#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if(a < b)
        cout << "a < b" << endl;
    else if(a > b)
        cout << "a > b" << endl;
    else
        cout << "a == b" << endl;

    return 0;
}