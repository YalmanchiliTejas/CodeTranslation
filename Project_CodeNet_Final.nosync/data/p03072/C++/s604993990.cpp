#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define int long long
using namespace std;

signed main() {
    int n;
    int h[20] = {0};
    int ans = 0;
    cin >> n;
    rep(i, n) {
        cin >> h[i];
        if (h[i] >= h[0] && h[i] >= h[1] && h[i] >= h[2] && h[i] >= h[3] && h[i] >= h[4] && h[i] >= h[5] && h[i] >= h[6] && h[i] >= h[7] && h[i] >= h[8] && h[i] >= h[9] && h[i] >= h[10] && h[i] >= h[11] && h[i] >= h[12] && h[i] >= h[13] && h[i] >= h[14] && h[i] >= h[15] && h[i] >= h[16] && h[i] >= h[17] && h[i] >= h[18] && h[i] >= h[19]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
