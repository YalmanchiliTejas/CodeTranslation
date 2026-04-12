#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') a = true;
        if (s[i] == 'B') b = true;
    }
    dump(a and b ? "Yes" : "No");
    return 0;
}
