#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0, i_l = (int)n; i < i_l; i++)
#define loop(i, a, b) for (int i = a; i < (int)(b); i++)

//
int N;
string s;

char reversed(char c) {
    return c == 'S' ? 'W' : 'S';
}


string solve(char first, char second) {
    char ans[N];
    ans[0] = first;
    ans[1] = second;

    loop(i, 2, N + 2) {
        int j0 = (i % N);
        int j1 = ((i - 1) % N);
        int j2 = ((i - 2) % N);

        char c1 = s[j1];
        char a1 = ans[j1];
        char a2 = ans[j2];

        if (c1 == 'o') {
            if (a1 == 'W') {
                ans[j0] = reversed(a2);
            } else {
                ans[j0] = a2;
            }
        } else {
            if (a1 == 'W') {
                ans[j0] = a2;
            } else {
                ans[j0] = reversed(a2);
            }
        }
    }
    if (ans[0] == first && ans[1] == second) {
        return string(ans, N);
    }
    return "";
}


int main() {
    cin >> N;
    cin >> s;

    for (int i = 0; i < 4; i++) {
        char c1 = (i / 2 == 0) ? 'S' : 'W';
        char c2 = (i % 2 == 0) ? 'S' : 'W';
        string a = solve(c1, c2);
        if (a.length() > 0) {
            cout << a << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
