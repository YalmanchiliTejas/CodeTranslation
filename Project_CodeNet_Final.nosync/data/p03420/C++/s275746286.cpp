#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int mod = 1e9+7;
const int maxn = 1e5+50;
const int inf = 1e9;

/*int bs(int n, int i)
{
    int l = 0, r = 1e6;
    while (l < r)
    {
        int m = (l + r) / 2;
        if ()
    }
}*/

int main()
{
   // freopen("in", "r", stdin);
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    if (!k) ans = (ll)n*n;
    else for (int i = k+1; i <= n; ++i)
    {
        ll t = (n + 1) / i;
        ans += t * (i - k);
        if (n % i >= k && n % i != i-1) ans += n - (t*i + k) + 1;
        //printf("%lld %lld\n", t, ans);
    }
    printf("%lld\n", ans);
    return 0;
}