#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 105;
int h, w;
bool H[N], W[N];
char a[N][N];

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                H[i] = true;
                W[j] = true;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        bool ok = false;
        for (int j = 0; j < w; ++j) {
            if (H[i] && W[j]) {
                ok = true;
                cout << a[i][j];
            }
        }
        if (ok)
            cout << endl;
    }
    return 0;
}
