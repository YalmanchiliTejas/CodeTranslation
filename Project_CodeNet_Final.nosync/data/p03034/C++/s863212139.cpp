#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
using i64 = int64_t;
i64 n;
vector<i64> s;
int main() {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    i64 ans = 0;
    for (int c = 1; c < n; ++c) {
        vector<bool> vis(n);
        i64 scr = 0;
        for (int i = 0; i < n; i += c) {
            int j = n - i - 1;
            i64 a = j, b = a - c;
            if (b <= 0) break;
            if (vis[i]) break;
            vis[i] = true;
            if (vis[j]) break;
            vis[j] = true;
            scr += s[i] + s[j];

       
            ans = max(ans, scr);
        }
    }
    cout << ans << endl;
    return 0;
}