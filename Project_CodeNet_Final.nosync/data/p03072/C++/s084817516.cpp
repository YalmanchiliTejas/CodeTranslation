#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>
#include <limits>
#include <iomanip>
#include <functional>
#include <array>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
const ll LL_MAX = 0x7fffffffffffffff;

int main()
{
    int n, h[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int h_max = h[0];
    int num = 1;
    for (int i = 1; i < n; i++)
    {
        if (h[i] >= h_max)
        {
            num++;
            h_max = h[i];
        }
    }
    cout << num;
    return 0;
}
