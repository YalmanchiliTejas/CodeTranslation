// https://atcoder.jp/contests/abc049/tasks/abc049_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s == "a" || s == "i" || s == "u" || s == "e" || s == "o") {
        cout << "vowel\n";
    } else {
        cout << "consonant\n";
    }
    return 0;
}
