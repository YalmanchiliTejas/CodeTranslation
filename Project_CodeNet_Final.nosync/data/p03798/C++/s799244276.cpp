#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, INDEX = 1;

int n;

string s;

bool isAns(bool a1, bool an) {
    bool a[MAX_N + INDEX];

    a[1] = a1;
    a[n] = an;

    a[2] = (s[0] == 'o') != (a[1] != a[n]);

    for (int i = 3; i < n; i++) {
        a[i] = (s[i - 2] == 'o') != (a[i - 1] != a[i - 2]);
    }

//    for (int i = 1; i <= n; i++) {
//        if (a[i]) {
//            cout << 'S';
//        } else {
//            cout << 'W';
//        }
//    }
//
//    cout << endl;

    for (int i = 1; i <= n; i++) {
        if (((s[i - 1] == 'o') == a[i]) != (a[i % n + 1] == a[(i + n - 2) % n + 1])) {
//            cout << i << endl;
//            cout << (a[i % n + 1] == a[(i + n - 2) % n + 1]) << endl;

            return false;
        }
    }

    return true;
}

void writeAns(bool a1, bool an) {
    bool a[MAX_N + INDEX];

    a[1] = a1;
    a[n] = an;

    a[2] = (s[0] == 'o') != (a[1] != a[n]);

    for (int i = 3; i < n; i++) {
        a[i] = (s[i - 2] == 'o') != (a[i - 1] != a[i - 2]);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            cout << 'S';
        } else {
            cout << 'W';
        }
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    cin >> s;

    if (isAns(true, true)) {
        writeAns(true, true);

        return 0;
    }

    if (isAns(true, false)) {
        writeAns(true, false);

        return 0;
    }

    if (isAns(false, true)) {
        writeAns(false, true);

        return 0;
    }

    if (isAns(false, false)) {
        writeAns(false, false);

        return 0;
    }

    cout << -1 << endl;

    return 0;
}
