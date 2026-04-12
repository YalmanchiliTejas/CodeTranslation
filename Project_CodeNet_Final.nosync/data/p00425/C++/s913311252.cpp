//https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0501?year=2006

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n, n) {
        int head = 1, front = 2, right = 3;
        int ans = head;

        for (int i = 0; i < n; ++i) {
            int h = head, f = front, r = right;

            string op;
            cin >> op;

            if (op == "North") {
                head = f;
                front = 7 - h;
            } else if (op == "East") {
                head = 7 - r;
                right = h;
            } else if (op == "West") {
                head = r;
                right = 7 - h;
            } else if (op == "South") {
                head = 7 - f;
                front = h;
            } else if (op == "Right") {
                front = r;
                right = 7 - f;
            } else if (op == "Left") {
                front = 7 - r;
                right = f;
            }
            ans += head;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
 *
 */
