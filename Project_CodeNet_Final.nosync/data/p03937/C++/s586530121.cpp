#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w;
    int cnt = 0;
    cin >> h >> w;
    rep (i, h) rep (j, w) {
        char c;
        cin >> c;
        if (c == '#') cnt++;
    }
    if (cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}

