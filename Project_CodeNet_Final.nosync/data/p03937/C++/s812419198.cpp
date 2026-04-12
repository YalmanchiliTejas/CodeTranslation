#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char a;
            cin >> a;
            if (a == '#') cnt++;
        }
    }
    string ans = "Impossible";
    if (cnt == h + w - 1) ans = "Possible";
    cout << ans << endl;
    return 0;
}