#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

int N;
int H[20];

int main() {
    cin >> N;
    rep(i, N) cin >> H[i];

    int ans = 0;
    int max = 0;
    rep(i, N) {
        if (max <= H[i]) {
            ans++;
            max = H[i];
        }
    }

    cout << ans << endl;
}