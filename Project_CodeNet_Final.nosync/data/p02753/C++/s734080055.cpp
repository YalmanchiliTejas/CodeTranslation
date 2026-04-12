#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int main() {
    string s = "";
    cin >> s;

    int a = 0;
    int b = 0;
    rep(i, 0, s.size()) {
        if (s[i] == 'A') {
            a++;
        } else {
            b++;
        }
        if (a > 0 && b > 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
