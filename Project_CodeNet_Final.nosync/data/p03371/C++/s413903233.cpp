#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstring>
#include <regex>
#include <sstream>

typedef long long ll;
constexpr double PI = 3.141592653589793;
constexpr ll INF = 1e18 + 10;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

using namespace std;
//    cout << setprecision(20) << ans << "\n";

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    ll maxi = max(x * 2, y * 2);
    ll sum = 1e+16;
    for (ll cnum = 0; cnum <= maxi; cnum++)
    {
        ll bnum = max(y - cnum, 0ll);
        ll anum = max(x - cnum, 0ll);
        ll current = anum * a + bnum * b + cnum * c * 2;
        if (sum > current)
        {
            sum = current;
        }
    }
    cout << sum << "\n";

    return 0;
}
