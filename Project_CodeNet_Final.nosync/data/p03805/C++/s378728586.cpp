#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define MOD 1000000007


int main() {
    int N, M;
    cin >> N >> M;
    vi G[10] = {};
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    vi v;
    rep(i, N-1) v.pb(i+1);
    int ans = 0;

    do {
        bool f = true;

        int c = 0, d = v[0];
        auto itr = find(all(G[c]), d);
            if (itr == G[c].end()) {
                f = false;
            }

        rep(i, N - 2) {
            int a = v[i], b = v[i + 1];
            auto itr = find(all(G[a]), b);
            if (itr == G[a].end()) {
                f = false;
                break;
            }
        }
        if (f) ans++;

    } while (next_permutation(all(v)));

    cout << ans << endl;

}
