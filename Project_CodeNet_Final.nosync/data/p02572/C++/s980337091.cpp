#include <bits/stdc++.h>
/*#ifndef LOCAL_RUN
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("fast-math")
    #pragma GCC target("avx2,tune=native")
#endif*/
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;

int main()
{
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
    //#else
        //freopen("cowcode.in", "r", stdin);
        //freopen("cowcode.out", "w", stdout);
    #endif
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ans = 0, sum = 0;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        ans += ll(t) * sum;
        ans %= MOD;
        sum = (sum + t) % MOD;
    }
    cout << ans;

    return 0;
}

// 272472LF
