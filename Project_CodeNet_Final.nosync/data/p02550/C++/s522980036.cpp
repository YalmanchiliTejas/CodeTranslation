#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X, M;
    cin >> N >> X >> M;

    ll n1 = X, key, cnt = 0, ans = 0;
    map<ll, bool> ma;
    vector<ll> v, vv;
    while (1) {
        if (cnt == N) {
            cout << ans << endl;
            return 0;
        }
        if (ma[n1]) {
            key = n1;
            break;
        }

        cnt++;
        ans += n1;
        v.push_back(n1);
        ma[n1] = true;
        n1 = (n1 * n1) % M;
    }

    N -= (cnt + 1);
    bool judge = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key)
            judge = 1;
        if (judge) {
            vv.push_back(v[i]);
        }
    }

    rep(i, vv.size() - 1) { vv[i + 1] += vv[i]; }

    ans += (N / (ll)vv.size()) * (ll)vv.back() + vv[N % (ll)vv.size()];

    cout << ans << endl;

    return 0;
}