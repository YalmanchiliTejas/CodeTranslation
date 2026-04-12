#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define PRINT(item) cout << (item) << endl;
#define PRINT_VEC(V) \
    for (auto v : (V)) cout << v << ' ';
#define PRINT_ENTER() cout << endl;
#define ll long long

int main() {
    /* code */
    string s;
    cin >> s;
    auto s_1 = s[0];
    REP(i, s.length()) {
        if (s_1 != s[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}