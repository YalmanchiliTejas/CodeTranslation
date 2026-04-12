#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define rrep(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////



int main() {
    ll n, x; cin >> n >> x;

    vector<ll> p(60), a(60);
    p[0] = 1;
    a[0] = 1;
    for (int i = 0; i < 50; i++)
    {
        p[i+1] = p[i]*2 + 1;
        a[i+1] = a[i]*2 + 3;
    }

    auto func = [&](auto &&func, int level, ll x) -> ll {
        if (level == 0) return 1;
        if (x == 1) return 0;
        if (x <= 1+a[level-1])      return func(func, level-1, x-1);
        if (x == 2+a[level-1])      return p[level-1] + 1;
        if (x <= 2+2*a[level-1])    return p[level-1] + 1 + func(func, level-1, x-2-a[level-1]);
        if (x == 3+2*a[level-1])    return 2*p[level-1] + 1;
    };
    ll ans = func(func, n, x);
    cout << ans << endl;

    return 0;
}
