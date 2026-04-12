#include"bits/stdc++.h"
using namespace std;

int N;
string s;

char answer(char left, char center, char right) {
    if ((center == 'S' && left == right) ||
        (center == 'W' && left != right)) {
        return 'o';
    } else {
        return 'x';
    }
}

bool isOK(string ans) {
    //0番目について
    if (answer(ans[N - 1], ans[0], ans[1]) != s[0]) {
        return false;
    }

    for (int i = 1; i < N - 1; i++) {
        if (answer(ans[i - 1], ans[i], ans[i + 1]) != s[i]) {
            return false;
        }
    }

    //N - 1番目について
    if (answer(ans[N - 2], ans[N - 1], ans[0]) != s[N - 1]) {
        return false;
    }

    return true;
}

int main() {
    cin >> N >> s;

    for (string ans : {"SS", "SW", "WS", "WW"}) {
        for (int i = 1; i < N - 1; i++) {
            if (s[i] == 'o') {
                if (ans[i - 1] == 'S' && ans[i] == 'S') {
                    ans += "S";
                } else if (ans[i - 1] == 'S' && ans[i] == 'W') {
                    ans += "W";
                } else if (ans[i - 1] == 'W' && ans[i] == 'S') {
                    ans += "W";
                } else if (ans[i - 1] == 'W' && ans[i] == 'W') {
                    ans += "S";
                } else {
                    assert(false);
                }
            } else {
                if (ans[i - 1] == 'S' && ans[i] == 'S') {
                    ans += "W";
                } else if (ans[i - 1] == 'S' && ans[i] == 'W') {
                    ans += "S";
                } else if (ans[i - 1] == 'W' && ans[i] == 'S') {
                    ans += "S";
                } else if (ans[i - 1] == 'W' && ans[i] == 'W') {
                    ans += "W";
                } else {
                    assert(false);
                }
            }
        }

        if (isOK(ans)) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}