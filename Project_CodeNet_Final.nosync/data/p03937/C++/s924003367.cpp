#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> table(h);
    rep(i, h) {
        cin >> table[i];
    }
    int count = 0;
    rep(i, h) {
        rep(j, w) {
            if (table[i][j] == '#') {
                count++;
            }
        }
    }
    if (count == h+w-1) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}