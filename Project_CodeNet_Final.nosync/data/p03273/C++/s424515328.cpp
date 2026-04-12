#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) { cin >> a.at(i); }

    vector<bool> resh(h, false);
    vector<bool> resw(w, false);
    rep(i, h) {
        rep(j, w) {
            if(a.at(i).at(j) == '#') {
                resh.at(i) = true;
                resw.at(j) = true;
            }
        }
    }

    rep(i, h) {
        if(resh.at(i)) {
            rep(j, w) {
                if(resw.at(j)) {
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}
