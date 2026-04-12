// 障害物'#'の場所(Xi,Yi)を辞書順ソートして、
// Xi <= X(i+1) かつ Yi <= Y(i+1)がすべてのiにおいて成り立つならば"Possible"
// そうでないなら"Impossible"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> Map(H);
    for (int i = 0; i < H; ++i) {
        cin >> Map[i];
    }
    vector<pair<int, int>> obst;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (Map[i][j] == '#') {
                obst.emplace_back(i, j);
            }
        }
    }
    sort(obst.begin(), obst.end());

    for (int i = 1; i < obst.size(); ++i) {
        if (obst[i - 1].first <= obst[i].first && obst[i - 1].second <= obst[i].second) {
            continue;
        }
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    return 0;
}