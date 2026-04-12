#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, H) { cin >> a[i]; }
    for (ll i = H - 1; i >= 0; i--) {
        if (a[i].find('#') == a[i].npos) {
            a.erase(a.begin() + i);
        }
    }
    for (ll i = W - 1; i >= 0; i--) {
        ll cnt = 0;
        rep(j, a.size()) {
            if (a[j][i] == '.') cnt++;
        }
        if (cnt == a.size()) {
            rep(j, a.size()) { a[j].erase(i, 1); }
        }
    }

    rep(i, a.size()) { cout << a[i] << endl; }

    return 0;
}
