#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = start; end <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
#define INF32 1'050'000'000
#define INF64 4'000'000'000'000'000'000
using ll = long long;
using namespace std;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> alp(N, vector<int>(26));
    vector<string> S(N);
    for (auto &&i : S) {
        cin >> i;
    }

    REP(i, N) {
        REP(j, S[i].size()) { alp[i][S[i][j] - 'a']++; }
    }

    vector<int> mn(26, INF32);
    REP(i, 26) {
        REP(j, N) { chmin(mn[i], alp[j][i]); }
    }

    REP(i, 26) {
        char s = 'a' + i;
        if (mn[i] != INF32)
            REP(j, mn[i]) { cout << s; }
    }
    std::cout << '\n';

    return 0;
}