#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

bool solve() {
    int H, W;

    cin >> H >> W;
    vector<string> A(H);
    REP(i, H) cin >> A[i];

    int cnt = 0;
    REP(i, H) {
        cnt += count(all(A[i]), '#');
    }

    if (cnt != H + W - 1) return false;

    int x = 0;
    int y = 0;
    while (x != H - 1 || y != W - 1) {
        bool can_move_x = x + 1 < H && A[x + 1][y] == '#';
        bool can_move_y = y + 1 < W && A[x][y + 1] == '#';
        if (can_move_x && !can_move_y) {
            ++x;
        } else if (!can_move_x && can_move_y) {
            ++y;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << (solve() ? "Possible" : "Impossible") << endl;

    return 0;
}
