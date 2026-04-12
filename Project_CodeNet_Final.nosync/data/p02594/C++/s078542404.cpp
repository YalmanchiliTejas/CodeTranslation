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
#include <functional> // greater など
#include <cmath>      // abs など
#include <numeric>    // accumulate, gcd など
#include <cassert>    // assert
#include <stdexcept>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef long long ll;

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

// constexpr inline ll mod = 1'000'000'007LL;
// constexpr int max_n = 200'000 + 5;

int main()
{
    // 高速な入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15); // 浮動小数の表示の精度

    int x; cin >> x;
    cout << (x >= 30 ? "Yes" : "No") << "\n";

    return 0;
}
