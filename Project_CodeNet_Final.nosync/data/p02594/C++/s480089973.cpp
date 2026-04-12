#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <time.h>
#pragma warning(disable:4996) 

typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define LINF3 1000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

void solve()
{
    int x;
    scanf("%d", &x);
    if (x >= 30) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }


    return;
}

int main()
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for (t = 0; t < T; t++) {
        //printf("Case #%d: ", t + 1);
        solve();
    }
#endif
    return 0;
}
