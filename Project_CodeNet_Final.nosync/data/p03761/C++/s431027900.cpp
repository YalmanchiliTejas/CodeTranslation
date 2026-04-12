// https://atcoder.jp/contests/abc058/tasks/arc071_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<char> st;
    REP(i, n) {
        multiset<char> t, u;
        string s;
        cin >> s;
        for (auto &x : s) {
            t.insert(x);
        }
        if (i == 0) {
            st = t;
        } else {
            // aとbの積集合を作る
            set_intersection(ALL(st), ALL(t), inserter(u, u.end()));
            st = u;
        }
    }
    for (auto &x : st) {
        cout << x;
    }
    cout << "\n";

    return 0;
}
