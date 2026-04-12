#include <iostream>

using namespace std;

struct state {
    int w, e, n, s, t, b;
} s;

void West() {
    state t = s;
    s.t = t.e, s.e = t.b, s.b = t.w, s.w = t.t;
};

void East() {
    state t = s;
    s.t = t.w, s.e = t.t, s.b = t.e, s.w = t.b;
}

void North() {
    state t = s;
    s.t = t.s, s.n = t.t, s.b = t.n, s.s = t.b;
}

void South() {
    state t = s;
    s.t = t.n, s.n = t.b, s.b = t.s, s.s = t.t;
}

void Left() {
    state t = s;
    s.n = t.e, s.e = t.s, s.s = t.w, s.w = t.n;
}

void Right() {
    state t = s;
    s.n = t.w, s.e = t.n, s.s = t.e, s.w = t.s;
}

int main() {
    int n;
    while (cin >> n) {
        s.w = 4; s.e = 3; s.n = 5; s.s = 2; s.t = 1; s.b = 6;
        if (n == 0) break;
        int sum = 1;
        for (int i = 0; i < n; i++) {
            string cmd; cin >> cmd;
            if (cmd == "West") {
                West();
            } else if (cmd == "East") {
                East();
            } else if (cmd == "North") {
                North();
            } else if (cmd == "South") {
                South();
            } else if (cmd == "Left") {
                Left();
            } else if (cmd == "Right") {
                Right();
            }
            sum += s.t;
        }
        cout << sum << endl;
    }
    return 0;
}