#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    int cnt[26] = {0};
    rep(i, n) {
        string s;
        cin >> s;

        int tmp[26] = {0};
        rep(j, s.size()) {
            ++tmp[s[j] - 'a'];
        }
        if (i == 0)
            rep(j, 26) cnt[j] = tmp[j];
        else
            rep(j, 26) cnt[j] = min(cnt[j], tmp[j]);
    }

    rep(i,26){
        rep(j,cnt[i]){
            cout << char('a' + i);
        }
    }
    cout << endl;

    return 0;
}