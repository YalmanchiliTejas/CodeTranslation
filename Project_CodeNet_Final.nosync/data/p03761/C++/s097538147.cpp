#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    if (n == 1) {
        sort(s[0].begin(), s[0].end());
        cout << s[0] << endl;
        return 0;
    }

    string ans = "";
    for (auto c : s[0]) {
        bool ok = true;
        rep(i, 1, n) {
            bool bl = false;
            rep(j, 0, (int)s[i].size()) {
                if (c == s[i][j]) {
                    bl = true;
                    s[i][j] = '-';
                    break;
                }
            }
            ok &= bl;
        }
        if(ok) ans.push_back(c);
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
}