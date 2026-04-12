#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll INF = 1 << 29;
const ll MOD = 1e9 + 7;

int main()
{
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    X -= Z;
    std::cout << X / (Y + Z) << std::endl;
}