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
//const long long MOD = 1000000007;
long long MOD = 998244353;

using namespace std;


void solve()
{
    ll n; int x;
    scanf("%lld%d%lld", &n, &x, &MOD);

    vector<ll> v;
    v.push_back(0);
    ll sum = 0;
    ll curr = x;
    map<ll, int> z;
    int prev = -1;
    int i;
    for (i = 0; i <= MOD; i++) {
        if(i>0) curr=curr*curr%MOD;
        auto it = z.find(curr);
        if (it != z.end()) {
            prev = it->second;
            break;
        }
        z[curr] = i;
        sum += curr;
        v.push_back(sum);
        if (v.size() == n+1) {
            printf("%lld\n", sum); return;
        }
    }
    assert(prev >= 0);
    assert(v.size() == i+1);
    int mm=i - prev;
    ll sum0 = v[i] - v[prev];

    ll num = n-i;
    ll ans1=(num / mm)*sum0;
    ll ans2 = v[num%mm+prev]-v[prev];
    ll ans = sum + ans1 + ans2;
    printf("%lld\n", ans);

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

