#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W; cin >> H >> W;
    vector<string> grid(H);
    rep(i, 0, H) cin >> grid[i];

    rep(hi, 0, H) {
        if (count(grid[hi].begin(), grid[hi].end(), '.') == W) {
            rep(wi, 0, W) grid[hi][wi] = '*';
        }
    }

    rep(wi, 0, W) {
        int count = 0;
        rep(hi, 0, H) if (grid[hi][wi] != '#') ++count;
        if (count == H) {
            rep(hi, 0, H) grid[hi][wi] = '*';
        }
    }

    rep(hi, 0, H) {
        bool printed = false;
        rep(wi, 0, W) {
            if (grid[hi][wi] != '*') {
                printed = true;
                cout << grid[hi][wi];
            }
        }
        if (printed) cout << "\n";
    }
}