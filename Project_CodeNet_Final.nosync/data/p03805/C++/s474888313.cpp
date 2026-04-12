#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

unordered_map<ll, ll> mp;

const int MAX_V = 100;
vector<int> G[MAX_V];

int V, E;
bool seen[MAX_V];

int dfs(int s) {
    seen[s] = true;
    int see_c = 0;
    rep(i, V) if (seen[i]) see_c++;
    int ret = 0;
    if (see_c == V) ret += 1;

    rep(i, G[s].size()) {
        if (!seen[G[s][i]]) {
            ret += dfs(G[s][i]);
        }
    }
    seen[s] = false;
    return ret;
}

void solve() {
    cout << dfs(0) << endl;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif
        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; ++i) {
            int s, t;
            scanf("%d %d", &s, &t);
            s--, t--;
            G[s].push_back(t);
            G[t].push_back(s);
        }

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}