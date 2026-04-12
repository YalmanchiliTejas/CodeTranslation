//絶望的に汚い
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const char* solve() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    int cnt = -1;
    for (auto& s : A) {
        cin >> s;
        cnt += count(s.cbegin(), s.cend(), '#');
    }
    int cw = 0, ch = 0, dw[] = {1, 0}, dh[] = {0, 1};
    while (cw != W - 1 || ch != H - 1) {
        bool f = false;
        for (int i = 0; i < 2; i++) {
            int tw = cw + dw[i], th = ch + dh[i];
            if (tw < 0 || tw >= W || th < 0 || th >= H) continue;
            if (A[th][tw] == '#') {
                f = true;
                cnt--;
                cw = tw;
                ch = th;
                break;
            }
        }
        if (!f) return "Impossible";
    }
    return cnt ? "Impossible" : "Possible";
}
int main() {
    cout << solve() << endl;
}
