#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> IN(h);
    for (auto & in : IN) {
        cin >> in;
    }
    vector<bool> col(h, true), row(w, true);

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (IN[i][j] == '#') {
                col[i] = false;
                row[j] = false;
            }
        }
    }

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (!col[i] && !row[j]) {
                cout << IN[i][j];
            }
        }
        if (!col[i]) {
            cout << endl;
        }
    }
}
