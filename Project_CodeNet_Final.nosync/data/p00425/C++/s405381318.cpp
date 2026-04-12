// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

struct Dice {
    // Left, Right, Front, Back, Down, Up
    int l, r, f, b, d, u;
    Dice() : u(1), f(2), r(3), l(4), b(5), d(6) {}
    bool operator<(const Dice &rhs) const {
        return l * 10 + r < rhs.l * 10 + rhs.r;
    }

    // y軸方向にプラス
    void RollN() {
        // ++y;
        int buff = d;
        d = b;
        b = u;
        u = f;
        f = buff;
    }

    // y軸方向にマイナス
    void RollS() {
        //  --y;
        int buff = d;
        d = f;
        f = u;
        u = b;
        b = buff;
    }

    // x軸方向にプラス
    void RollE() {
        // ++x;
        int buff = d;
        d = r;
        r = u;
        u = l;
        l = buff;
    }

    // x軸方向にマイナス
    void RollW() {
        // --x;
        int buff = d;
        d = l;
        l = u;
        u = r;
        r = buff;
    }

    // 90度→方向に回転
    void RollL() {
        // ----->
        int buff = f;
        f = l;
        l = b;
        b = r;
        r = buff;
    }

    // 90度←方向に回転
    void RollR() {
        // <------
        int buff = f;
        f = r;
        r = b;
        b = l;
        l = buff;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        auto dice = Dice();
        int sum = 1;
        while (N--) {
            string s;
            cin >> s;
            if (s == "North") {
                dice.RollN();
            } else if (s == "East") {
                dice.RollE();
            } else if (s == "South") {
                dice.RollS();
            } else if (s == "West") {
                dice.RollW();
            } else if (s == "Right") {
                dice.RollR();
            } else if (s == "Left") {
                dice.RollL();
            } else {
                cout << "Error" << endl;
                return 0;
            }
            sum += dice.u;
        }
        cout << sum << endl;
    }

    return 0;
}

