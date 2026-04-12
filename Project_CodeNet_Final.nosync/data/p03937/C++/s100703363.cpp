#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int cnt = 0;
    rep(i, H) rep(j, W) {
        char c;
        cin >> c;
        if (c == '#') ++cnt;
    }
    if (cnt == H + W - 1) cout << "Possible\n";
    else cout << "Impossible\n";
    return 0;
}
