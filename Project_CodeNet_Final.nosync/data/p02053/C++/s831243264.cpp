#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> hw(H);
    const int inf = 1e8;
    int xmi = inf, xma = -inf, ymi = inf, yma = -inf;
    rep(i, H) {
        cin >> hw[i];
        rep(j, W) {
            if (hw[i][j] == 'B') {
                xmi = min(xmi, j);
                xma = max(xma, j);
                ymi = min(ymi, i);
                yma = max(yma, i);
            }
        }
    }

    // 列挙
    vector<P> pos;
    rep(r, H) rep(c, W) {
        if (hw[r][c] == 'B' and (r == ymi or r == yma or c == xmi or c == xma)) pos.emplace_back(r, c);
    }

    int ans = -inf;
    rep(i, pos.size()) rep(j, pos.size()) {
        ans = max(ans, abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second));
    }

    cout << ans << endl;
    return 0;
}

