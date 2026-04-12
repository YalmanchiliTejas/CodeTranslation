#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    const ll d[][2] = {{0, 1}, {1, 0}};
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    queue<pair<ll, ll>> q;
    q.push(make_pair(0, 0));
    vector<vector<ll>> dist(h, vector<ll>(w, inf));
    dist[0][0] = 0;
    while(!q.empty()) {
        pair<ll, ll> p = q.front(); q.pop();
        ll cnt = 0;
        rep(i, 2) {
            ll nx = p.first + d[i][0];
            ll ny = p.second + d[i][1];
            ll nd = dist[p.second][p.first] + 1;
            if ((nx < 0) || (nx >= w) || (ny < 0) || (ny >= h)) continue;
            if (s[ny][nx] != '#') continue;
            if (dist[ny][nx] <= nd) continue;
            dist[ny][nx] = nd;
            q.push(make_pair(nx, ny));
            cnt++;
        }
        if (cnt > 1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    bool f = true;
    rep(i, h) {
        rep(j, w) {
            if ((s[i][j] == '#') && (dist[i][j] == inf)) {
                f = false;
            }
        }
    }
    cout << (f ? "Possible" : "Impossible") << endl;
    return 0;
}
