#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXW = 100;

    int A, B;
    cin >> A >> B;

    vvi d(A + 1, vi(B + 1));
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++)
            cin >> d[i][j];
    }

    vvi c(MAXW + 1, vi(MAXW + 1));
    for (int xc = 0; xc <= MAXW; xc++) {
        for (int yc = 0; yc <= MAXW; yc++) {
            for (int x = 1; x <= A; x++) {
                for (int y = 1; y <= B; y++) {
                    c[xc][yc] = max(c[xc][yc], d[x][y] - xc * x - yc * y);
                }
            }
        }
    }

    for (int x = 1; x <= A; x++) {
        for (int y = 1; y <= B; y++) {
            int sp = INT_MAX;
            for (int xc = 0; xc <= MAXW; xc++) {
                for (int yc = 0; yc <= MAXW; yc++) {
                    sp = min(sp, xc * x + yc * y + c[xc][yc]);
                }
            }
            if (sp != d[x][y]) { cout << "Impossible\n"; return 0; }
        }
    }

    int XL = 1, YL = XL + MAXW + 1;
    int V = YL + MAXW + 1, E = MAXW + MAXW + (MAXW + 1) * (MAXW + 1);

    cout << "Possible\n";
    cout << V << " " << E << "\n";
    for (int xc = 1; xc <= MAXW; xc++)
        cout << (XL + xc - 1) << " " << (XL + xc) << " X\n";
    for (int yc = 0; yc < MAXW; yc++)
        cout << (YL + yc + 1) << " " << (YL + yc) << " Y\n";
    for (int xc = 0; xc <= MAXW; xc++)
        for (int yc = 0; yc <= MAXW; yc++)
            cout << (XL + xc) << " " << (YL + yc) << " " << c[xc][yc] << "\n";

    cout << 1 << " " << YL << "\n";

    return 0;
}

