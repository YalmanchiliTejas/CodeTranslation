#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    if ((r * 100 + g * 10 + b) % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}