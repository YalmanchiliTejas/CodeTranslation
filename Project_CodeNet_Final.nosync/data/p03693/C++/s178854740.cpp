#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

#ifndef INT_MAX
#  define INT_MAX std::numeric_limits<int>().max()
#endif
#ifndef INT_MIN
#  define INT_MIN std::numeric_limits<int>().min()
#endif
#define LL_MAX std::numeric_limits<ll>().max()
#define LL_MIN std::numeric_limits<ll>().min()
#define INF LL_MAX

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
// 配列の初期化
#define ZERO(p) memset(p, 0, sizeof(p))
// 配列の初期化(-1)
#define MINUS(p) memset(p, 1, sizeof(p))

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;
    if(num % 4 == 0) { printf("YES\n"); }
    else { printf("NO\n"); }
    return 0;
}
