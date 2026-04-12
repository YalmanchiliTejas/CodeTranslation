#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
using namespace std;

const int INF = 100100100;

int main() {
    int n; cin >> n;
    string s[60];
    rep(i, 0, n) {
        cin >> s[i];
    }
    string ans;
    rep(c, 'a', 'z' + 1) {
        int small = INF;
        rep(i, 0, n) {
            int cnt = 0;
            rep(j, 0, s[i].size()) {
                if (s[i][j] == c) {
                    cnt++;
                }
            }
            small = min(small, cnt);
        }
        rep(i, 0, small) ans += c;
    }
    cout << ans << endl;
}
