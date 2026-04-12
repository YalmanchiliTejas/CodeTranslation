#include <bits/stdc++.h>
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)

using namespace std;

int main() {
    //freopen("a.inp", "r", stdin);
    int h, w, cnt = 0;
    char c;
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            cin >> c;
            if (c == '#') ++cnt;
        }
    cout << (cnt == h + w - 1 ? "Possible" : "Impossible");
    return 0;
}