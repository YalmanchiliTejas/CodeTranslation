#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> ss(h);
    for (int i = 0; i < h; i++) cin >> ss[i];

    vector<pair<int, int>> ps;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ss[i][j] == 'B') ps.emplace_back(i, j);
        }
    }

    int nax = 0;
    sort(ps.begin(), ps.end(), [](auto &a, auto &b) {
       return a.first + a.second < b.first + b.second;
    });
    nax = max(nax, abs(ps.front().first - ps.back().first) + abs(ps.front().second - ps.back().second));

    sort(ps.begin(), ps.end(), [](auto &a, auto &b) {
        return a.first - a.second < b.first - b.second;
    });
    nax = max(nax, abs(ps.front().first - ps.back().first) + abs(ps.front().second - ps.back().second));

    cout << nax << endl;
}
