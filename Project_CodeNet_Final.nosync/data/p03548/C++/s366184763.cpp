#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <cstring>
#include <cctype>
#include <ctype.h>

#define INF 100000000

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x - z) / (y + z) << endl;
    return 0;
}
