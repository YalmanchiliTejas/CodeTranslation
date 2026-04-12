#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    ll N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll ans = 0;
    queue<vector<ll>> queue;
    queue.push(vector<ll>(1, 0));
    while (!queue.empty()) {
        vector<ll> route = queue.front();
        queue.pop();
        if (route.size() == N) {
            ans++;
        } else {
            ll v = route.back();
            for (ll u : graph[v]) {
                if (find(route.begin(), route.end(), u) == route.end()) {
                    vector<ll> target = route;
                    target.push_back(u);
                    queue.push(target);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
