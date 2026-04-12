#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>
#include <bitset>
#include <cstdint>
using namespace std;

#ifdef DEBUG
#include <cassert>
#else
#define assert(x)
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
using ll = long long;

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

int main()
{
    // 高速な入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 浮動小数の表示の精度
    cout << setprecision(15);

    vector<char> v(3);
    rep(i, 3) { cin >> v[i]; }
    if (v[0] == v[1] && v[1] == v[2])
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }

    return 0;
}
