#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int dh[2] = {1, 0};
const int dw[2] = {0, 1};

int H, W;

void dfs(vector<string> &G, vector<vector<int>> &S, int h, int w) {
    S[h][w] = 1;
    if (h == H - 1 && w == W - 1) return;

    int nexth = -1, nextw = -1;
    REP(i, 0, 2) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;    
        if (G[nh][nw] == '#') {
            if (nexth != -1 && nextw != -1) return;
            nexth = nh; nextw = nw;
        }
    }
    if (nexth == -1 && nextw == -1) return;
    dfs(G, S, nexth, nextw);
    return;
}

int main() {
    cin >> H >> W;
    vector<string> G(H);
    REP(i, 0, H) cin >> G[i];

    vector<vector<int>> S(H, vector<int>(W, 0));
    dfs(G, S, 0, 0);

    REP(i, 0, H) {
        REP(j, 0, W) {
            if (G[i][j] == '#' && S[i][j] == 0) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}