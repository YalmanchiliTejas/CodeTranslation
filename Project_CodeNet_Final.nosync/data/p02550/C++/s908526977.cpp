#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <iomanip>
#include <cassert>
#include <numeric>
using namespace std;
 
#define ff first
#define ss second
#define pb push_back 
 
using LL = long long int;
using VL = vector<LL>;
using VI = vector<int>;
using VVL = vector<VL>;
using PLL = pair<LL,LL>;
using PII = pair<int ,int>;
 
#ifdef DEBUG
void _print()
{
  cout << endl;
}
template<typename T, typename... Args >
void _print(const T first_elem, const Args... args)
{
  cout << first_elem << " ";
  _print(args...);
}
#else
void _print()
{
}
template<typename T, typename... Args >
void _print(const T first_elem, const Args... args)
{
}
#endif
 
 
// NOTE: Please dont implement _print() as function in your program. It is reserved
// for debug purpose.

int main()
{
    ios::sync_with_stdio(false);
    LL n, x, m;
    cin >> n >> x >> m;
    LL sum = 0;
    map<LL, LL> vals;
    LL current = x;
    LL cycleLen = 0;
    LL initial = 0;
    LL len = 0;
    for (int i = 0; i < n; i++) {
        if (vals.count(current)) {
            initial = vals[current];
            cycleLen = i;
            len = i - initial;
            break;
        }

        vals[current] = i;
        current = (current * current) % m;
    }

    LL ans = 0;
    current = x;
    for (int i = 0; i < initial; i++) {
        ans += current;
        current = (current * current) % m;
    }

    LL cycleSum = 0;
    LL currentAtInitial = current;
    for (int i = initial; i < cycleLen; i++) {
        cycleSum += current;
        current = (current * current) % m;
    }

    LL totalCycle = len ? (n - initial) / len : 0;
    ans += (cycleSum * totalCycle);

    n -= (len * totalCycle);
    n -= initial;
    _print(totalCycle, initial, len, n, currentAtInitial, ans);

    current = currentAtInitial;
    for (int i = 0; i < n; i++) {
        ans += current;
        current = (current * current) % m;
    }

    cout << ans << endl;

    return 0;
}