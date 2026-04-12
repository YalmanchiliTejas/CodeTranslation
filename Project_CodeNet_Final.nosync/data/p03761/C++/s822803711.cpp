#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int n;
int m[28];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    rep(i, 26) m[i] = 100;
    rep(i, n) {
        string S; cin >> S;
        rep(j, 26) {
            int cnt = 0;
            rep(k, S.size()) if (S[k]-'a'==j) cnt++;
            m[j] = min(m[j], cnt);
        }
    }
    string ans;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    rep(i, 26) rep(j, m[i]) ans += alpha[i];
    cout << ans << endl;
}