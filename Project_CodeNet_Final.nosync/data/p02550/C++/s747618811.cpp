// 問題の URL を書いておく
// 

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

ll p[100005] = {};
ll pi[100005] = {};
ll sum[100005] = {};
int main(int, const char**)
{
    ll n, x, m;
    cin >> n >> x >> m;
    ll t = x;
    ll index = 1;
    while(p[t] == 0)
    {
        Print(t);
        if(t == 0)
        {
            break;
        }
        p[t] = t * t % m;
        Print(p[t]);
        pi[t] = index;
        Print(pi[t]);
        sum[index] = sum[index - 1] + t;
        index++;
        t = p[t];
    }

    auto loopCount = index - pi[t];
    auto headCount = index - 1 - loopCount;
    Print(headCount);
    Print(loopCount);
    Print(t);
    Print(index);
    Print(pi[t]);
    Print(sum[index - 1]);
    Print(sum[pi[t] - 1]);
    auto loopSum = sum[index - 1] - sum[pi[t] - 1];
    Print(loopSum);

    if(t == 0)
    {
        auto ti = min(index - 1, n);
        cout << sum[ti] << endl;
        return 0;
    }

    if(n <= headCount)
    {
        cout << sum[n] << endl;
        return 0;
    }

    auto rest = n - headCount;
    Print(rest);
    auto lc = rest / loopCount;
    Print(lc);
    auto lm = rest % loopCount;
    Print(lm);
    auto ms = sum[headCount + lm] - sum[headCount];
    Print(ms);
    auto ans = lc * loopSum + ms + sum[headCount];
    cout << ans << endl;    

    return 0;
}
