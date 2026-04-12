#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int h, w;
    cin >> h >> w;

    int cnt = 0;
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            if (s[j] == '#') ++cnt;
        }
    }

    if (h + w - 1 == cnt)
        cout << "Possible";
    else
        cout << "Impossible";
    cout << endl;

    return 0;
}