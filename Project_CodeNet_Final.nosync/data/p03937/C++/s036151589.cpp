#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int H, W; cin >> H >> W;
    vector<string> A(H); for (auto &s : A) cin >> s;
    int cnt = 0;
    for (auto &s : A) cnt += count(begin(s), end(s), '#');
    cnt--;
    int y = 0, x = 0;
    for (;;) {
        if (y == H-1 && x == W-1) {
            cout << (cnt == 0 ? "Possible" : "Impossible") << endl;
            break;
        } else if (x + 1 < W && A[y][x+1] == '#') {
            x = x + 1;
            cnt--;
        } else if (y + 1 < H && A[y+1][x] == '#') {
            y = y + 1;
            cnt--;
        } else {
            cout << "Impossible" << endl;
            break;
        }
    }
    return 0;
}