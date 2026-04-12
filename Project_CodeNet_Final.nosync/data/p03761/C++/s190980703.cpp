#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> ans(26, 0);
    int count = 1;
    while (count <= n) {
        string S;
        cin >> S;
        if (count == 1) {
            rep(i, S.size()) {
                ans[(int)(S[i]-'a')]++;
            }
            count++;
            continue;
        }
        vector<int> res(26, 0);
        rep(i, S.size()) {
            res[(int)(S[i]-'a')]++;
        }
        rep(i, 26) {
            ans[i] = min(ans[i], res[i]);
        }
        count++;
    }
    string answer;
    rep(i, 26) {
        rep(j, ans[i]) {
            answer += (char)('a' + i);
        }
    }
    cout << answer << endl;
}
