#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

LLONG lengths[51], patties[51];

LLONG GetPattyNum(LLONG N, LLONG X)
{
    if (X == 1) return N == 0 ? 1 : 0;
    else if (X <= lengths[N - 1] + 1) return GetPattyNum(N - 1, X - 1);
    else if (X == lengths[N - 1] + 2) return patties[N - 1] + 1;
    else return GetPattyNum(N - 1, X - lengths[N - 1] - 2) + patties[N - 1] + 1;
}

int main()
{
    LLONG N, X; cin >> N >> X;
    lengths[0] = 1; patties[0] = 1;
    for (int l = 1; l <= 50; ++l)
    {
        lengths[l] = lengths[l - 1] * 2 + 3;
        patties[l] = patties[l - 1] * 2 + 1;
    }
    cout << GetPattyNum(N, X) << endl;
}