#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
constexpr int INF = 1e9;

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    string S;
    cin >> S;

    string ans;
    bool ok = false;
    vector<string> c = {"SS", "SW", "WS", "WW"};
    for (auto x:c) {
        ans = x;
        FOR (index, 1, n) {
            if (ans[index] == 'S') {
                if (S[index] == 'o') {
                    ans += (ans[index-1] == 'S' ? "S" : "W");
                } else {
                    ans += (ans[index-1] == 'S' ? "W" : "S");
                }
            } else {
                if (S[index] == 'x') {
                    ans += (ans[index-1] == 'S' ? "S" : "W");
                } else {
                    ans += (ans[index-1] == 'S' ? "W" : "S");
                }
            }
        }
        //cout << ans << endl;
        if (ans[0] == 'S') {
            if (S[0] == 'o') {
                if (ans[n-1] != ans[1]) continue;
            } else {
                if (ans[n-1] == ans[1]) continue;
            }
        } else {
            if (S[0] == 'x') {
                if (ans[n-1] != ans[1]) continue;
            } else {
                if (ans[n-1] == ans[1]) continue;
            }
        }
        if (ans[0] == ans[n]) {
            REP(i,n) cout << ans[i];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}