#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const int INF = 100;

int main()
{
    int n;
    cin >> n;
    vector<int> c(26, INF);
    rep(i, n) {
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        rep(j, s.size()) {
            cnt[s[j] - 'a']++;
        }
        rep(j, 26) {
            c[j] = min(c[j], cnt[j]);
        }
    }
    string ans;
    rep(i, 26) {
        rep(j, c[i]) {
            ans.push_back('a' + i);
        }
    }
    cout << ans << endl;
    return 0;
}
