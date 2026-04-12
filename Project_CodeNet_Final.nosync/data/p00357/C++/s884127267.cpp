//https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0362?year=2017

#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<int> &vt) {
    int cur = 0;
    for (int i = 0; i < vt.size(); ++i) {
        if (cur < i) return false;
        cur = max(cur, vt[i] + i);
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> fwd;//行き
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        fwd.emplace_back(t / 10);//いくつ先のトランポリンまで行けるか
    }

    vector<int> bwd;//帰り
    bwd = fwd;
    reverse(bwd.begin(), bwd.end());

    if (solve(fwd) && solve(bwd)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

/*
 * 距離が短いトランポリンも一応踏んで
 * cur = max(cur, vt[i] + i)
 * で現在位置を更新していく。
 *
 */
