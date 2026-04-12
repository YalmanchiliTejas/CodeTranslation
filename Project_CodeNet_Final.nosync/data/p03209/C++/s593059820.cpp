// 問題の URL を書いておく
// https://atcoder.jp/contests/abc115/tasks/abc115_d

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

const int MaxLayer = 51;

ll len[MaxLayer] = {}, p[MaxLayer] = {};

ll count(int layer, ll index)
{
    if(layer == 0)
    {
        return 1;
    }

    if(!(index >= 0 && index < len[layer]))
    {
        printf("layer: %d, index: %ld, len: %ld\n", layer, index, len[layer]);
        abort();
    }

    if(index == 0)
    {
        return 0;
    }
    auto center = (len[layer] - 1) / 2;

    if(index < center)
    {
        return count(layer - 1, index - 1);
    }
    if(index == center)
    {
        return p[layer - 1] + 1;
    }
    if(index == len[layer] - 1)
    {
        return p[layer];
    }
    return p[layer - 1] + 1 + count(layer - 1, index - len[layer - 1] - 2);
}

int main(int, const char**)
{
    ll n, x;
    cin >> n >> x;
    len[0] = 1;
    p[0] = 1;
    rep(i, n)
    {
        len[i + 1] = len[i] * 2 + 3;
        p[i + 1] = p[i] * 2 + 1;
    }

#if 0
    rep(i, n + 1)
    {
        printf("[%d]: len: %ld, p: %ld\n", i, len[i], p[i]);
    }
#endif
    auto c = count(n, x - 1);
    cout << c << endl;

#if 0
    cout << endl;
    int ly = 3;
    rep(i, len[ly])
    {
        cout << "i: " << i << ", count: " << count(ly, i) << endl;
    }
#endif
    return 0;
}
