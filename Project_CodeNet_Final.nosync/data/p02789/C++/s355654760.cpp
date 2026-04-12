#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

#define rep(countName, left, right, up) for (ll countName = left; countName < right; countName += up)
#define rev(countName, right, left, down) for (ll countName = right - 1; countName >= left; countName -= down)

auto solve1(void)
{
    int n, m;
    cin >> n >> m;

    if (n == m)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main(void)
{
    cout << solve1() << endl;
    return 0;
}