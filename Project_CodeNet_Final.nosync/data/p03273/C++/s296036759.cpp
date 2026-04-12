#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    int H, W;
    cin >> H >> W;
    vector<vector<char>> cell(H, vector<char>(W));
    Vi hs, ws;
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++) {
            cell[i][j] = S[j];
            if (S[j] == '#') {
                hs.emplace_back(i);
                ws.emplace_back(j);
            }
        }
    }

    sort(hs.begin(), hs.end());
    sort(ws.begin(), ws.end());

    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    ws.erase(unique(ws.begin(), ws.end()), ws.end());

    for (const auto& h : hs) {
        for (const auto& w : ws) {
            cout << cell[h][w];
        }
        cout << "\n";
    }

    return 0;
}