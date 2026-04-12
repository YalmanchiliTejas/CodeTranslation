#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;

int64_t height[MAXN], patties[MAXN]; // spondge bob can go fuck himself with his shitty crabby patties

void precalc () {
    height[0] = patties[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        height[i] = 2 * height[i - 1] + 3;
        patties[i] = 2 * patties[i - 1] + 1;
    }
}

signed main () {
    precalc();
    
    int64_t n, x;
    cin >> n >> x;
    int64_t ans = 0;
    for (int64_t j = n; j >= 0 && (x > 0); --j) {
        if (height[j] <= x) {
            ans += patties[j];
            x -= height[j];
            if (x) {
                ++ans;
                --x;
            }
            if (x >= height[j] - j) {
                ans += patties[j];
                x = 0;
            }
        }
        --x;
    }
    cout << ans << '\n';
}
