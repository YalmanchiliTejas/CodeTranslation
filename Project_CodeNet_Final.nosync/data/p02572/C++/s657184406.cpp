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
    LL n;
    cin >> n;
    LL mod = 1e9 + 7;
    LL sum = 0;
    LL ans = 0;
    VL a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = (ans + (a[i] * sum) % mod) % mod;
        sum = (sum + a[i]) % mod;
    }

    cout << ans << endl;
    return 0;
}