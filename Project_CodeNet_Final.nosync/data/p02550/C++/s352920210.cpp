#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
ll N, X, M;

vector<ll> w;


void input() {
    cin >> N >> X >> M;
}


int main() {
    input();
    map<int, int> m;
    w = vector<ll>(2 * M + 2);
    w[0] = 0;
    m[0] = 0;
    w[1] = X;
    m[X] = 1;
    int n = 1;
    ll v = X;
    rep(i, 2 * M + 1) {
        v = v * v % M;
        if (m.count(v)) break;
        m[v] = n + 1;
        w[n + 1] = w[n] + v;
        n++;
        if (n == N) {
            cout << w[n] << endl;
            return 0;
        }
    }
    ll ans = w[n];
    ll dn = N - n;
    int i = m[v];
    if (i == 0) {
        cout << ans << endl;
        return 0;
    }
    vector<ll> l;
    for (int j = i; j <= n; j++) {
        l.push_back(w[j] - w[i - 1]);
    }
    int ln = l.size();
    ans += l.back() * (dn / ln);
    if (dn % ln != 0) ans += l[dn % ln - 1];
    cout << ans << endl;
}
