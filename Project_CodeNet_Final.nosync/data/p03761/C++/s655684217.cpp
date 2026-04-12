#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define llong long long int
#define ullong unsigned long long int
#define rep(i, n) for (int i = 0; i < n; ++i)

const static long long int MOD = 1000000000 + 7;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, alphabet_cnt[51][26] = {};
    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            ++alphabet_cnt[i][s[j] - 'a'];
        }
    }

    int minimum_alphabet_cnt[26] = {};
    rep(i, 26) {
        int min_cnt = 51;
        rep(j, n) {
            min_cnt = min(min_cnt, alphabet_cnt[j][i]);
        }
        minimum_alphabet_cnt[i] = min_cnt;
    }

    string ans = "";
    rep(i, 26) {
        string tmp(minimum_alphabet_cnt[i], 'a' + i);
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}