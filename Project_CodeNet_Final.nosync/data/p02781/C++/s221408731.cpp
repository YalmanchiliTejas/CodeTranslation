#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int K;

// メモ化再帰により一つ下の桁から上の桁へ遷移していくdp
ll solve(string &s, int k = 0, bool status = 1, int c = 0) {
    // dp[k][status] := 上(k+1)桁が定まっていてその時点でstatus(:=
    // 上限値と一致するかの真偽値)のときの場合の数
    static ll dp[100001][2][4];
    static bool visited[1000001][2][4] = {};
    static int max_num = 9;

    if (k == s.size()) {
        return (c == K);
    }

    ll &res = dp[k][status][c];
    if (visited[k][status][c])
        return res;
    else
        res = 0;

    visited[k][status][c] = true;
    int r = (status ? s[k] - '0' : max_num);

    for (int i = 0; i <= r; i++) {
        if (c == K && i) break;
        ll cnt = solve(s, k + 1, status && i == r, c + (i > 0));
        res += cnt;
    }
    return res;
}

int main() {
    string N;
    cin >> N >> K;
    cout << solve(N) << endl;
    return 0;
}