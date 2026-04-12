#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(a) (a).begin(), (a).end()

#define INF 1000000000

using namespace std;

int main() {
    string s;
    cin >> s;
    bool ok = false;

    for (int i = 0; i < 2; ++i) {
        if (s[i] != s[i+1])
            ok = true;
    }

    cout << (ok?"Yes":"No") << endl;
    return 0;
}
