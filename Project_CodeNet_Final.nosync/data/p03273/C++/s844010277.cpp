#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).rbegin(), (a).rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) a.begin(), a.end()
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    REP(i, h) cin >> s[i];

    vector<bool> row(h, false);
    vector<bool> col(w, false);
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    REP(i, h) {
        if (row[i]) {
            REP(j, w) {
                if (col[j]) {
                    cout << s[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}