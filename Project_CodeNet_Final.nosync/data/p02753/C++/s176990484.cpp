#include <iostream>
#include <string>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
    string s;
    int cnt = 0;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    REP(i, s.length()) {
        if (s[i] == 'A') {
            cnt++;
        }
    }

    cout << (cnt == 0 || cnt == 3? "No" : "Yes") << "\n";
    return 0;
}