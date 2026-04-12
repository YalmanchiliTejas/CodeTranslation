#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;

    int h[n];
    rep(0, n) cin >> h[i];

    int cnt = 0;
    bool possible;
    rep(1, n) {
        possible = true;
        for (int j = 0; j < i; j++) {
            if (i != j && h[i] < h[j]) {
                possible = false;
                break;
            }
        }

        if (possible) cnt++;
    }

    cout << (cnt + 1) << endl;
}

int main() {
    solve();

    return 0;
}
