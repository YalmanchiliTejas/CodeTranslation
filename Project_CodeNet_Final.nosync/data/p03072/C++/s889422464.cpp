#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
    //入力
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    //
    int ans = 0;
    rep(i, n) {
        int flg = 0;
        rep(j, i) {
            if (h[j] > h[i]) {
                ++flg;
                break;
            }
        }
        if (flg == 0) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}