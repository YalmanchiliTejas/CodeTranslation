#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = double;
const ld EPS = 1e-7;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 300001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif

    fast_io();

    cout.precision(6);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    int h, w;
    cin >> h >> w;
    vector<string> maze(h);
    for (int i = 0; i < h; ++i) {
        cin >> maze[i];
    }
    vector<vector<int>> used(h, vector<int>(w));
    int i = 0, j = 0;
    used[0][0] = 1;
    while (!(i == h - 1 && j == w - 1)) {

        int deg = 0;
        int ni, nj;
        for (int dx:{-1, 1}) {
            if (i + dx >= 0 && i + dx < h && maze[i + dx][j] == '#') {
                ++deg;
                if (!used[i + dx][j]) {
                    ni = i + dx;
                    nj = j;
                    used[i + dx][j] = 1;
                }
            }
            if (j + dx >= 0 && j + dx < w && maze[i][j + dx] == '#') {
                ++deg;
                if (!used[i][j + dx]) {
                    ni = i;
                    nj = j + dx;
                    used[i][j + dx] = 1;
                }
            }
        }
        if (deg == 1 && i == 0 && j == 0 || !(i == 0 && j == 0) && deg == 2) {
            if (ni < i || nj < j) {
                cout << "Impossible";
                return 0;
            }
            i = ni;
            j = nj;
        } else {
            cout << "Impossible";
            return 0;
        }
    }
    int deg = 0;
    int ni, nj;
    for (int dx:{-1, 1}) {
        if (i + dx >= 0 && i + dx < h && maze[i + dx][j] == '#') {
            ++deg;
            if (!used[i + dx][j]) {
                ni = i + dx;
                nj = j;
                used[i + dx][j] = 1;
            }
        }
        if (j + dx >= 0 && j + dx < w && maze[i][j + dx] == '#') {
            ++deg;
            if (!used[i][j + dx]) {
                ni = i;
                nj = j + dx;
                used[i][j + dx] = 1;
            }
        }
    }
    if (deg > 1) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible";
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

