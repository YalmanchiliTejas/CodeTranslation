#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int h, w;
    cin >> h >> w;
    int r = -1;
    string ans = "Possible";
    rep(i,h) {
        string s;
        cin >> s;
        rep(j,w) {
            if (s[j] == '#') {
                if (j < r) {
                    ans = "Impossible";
                }
                r = j;
            }
        }
    }
    cout << ans << endl;
}