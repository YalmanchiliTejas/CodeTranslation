#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    int cnt[26] = {0};

    string S;
    cin >> S;
    rep(i, S.size()) {
        ++cnt[int(S[i] - 'a')];
    }

    rep(i, N - 1) {
        cin >> S;
        int tmp[26] = {0};
        rep(j, S.size()) {
            ++tmp[int(S[j] - 'a')];
        }

        rep(j, 26)
            cnt[j] = min(cnt[j], tmp[j]);
    }

    rep(i, 26) {
        rep(j, cnt[i]) cout << char('a' + i);
    }
    cout << endl;

    return 0;
}