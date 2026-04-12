#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;

ll dsu[SIZE], sz[SIZE];

ll find(int v) {
    if (dsu[v] == v) return v;
    else return dsu[v] = find(dsu[v]);
}

void uni(int v, int u) {
    v = find(v);
    u = find(u);
    if (u != v) {
        sz[v] += sz[u];
        dsu[u] = v;
    }
}

int main()
{
    fastInp;
    
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    ll s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s * vec[i];
        ans %= MOD;
        s += vec[i];
        s %= MOD;
    }

    cout << ans;

    return 0;
}