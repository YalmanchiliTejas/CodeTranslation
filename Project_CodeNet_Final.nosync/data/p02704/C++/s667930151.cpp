#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()
#define ull unsigned long long

const int MAXN = 505;

int n;
int rowOr[MAXN], colOr[MAXN];
ull rows[MAXN], cols[MAXN];
ull ans[MAXN][MAXN];
bool ok = true;

int r[MAXN], c[MAXN];
int a[MAXN][MAXN];

void doIt() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            a[i][j] = 0;

    for (int i = 0; i < n; i++) {
        if (rowOr[i] == false && r[i]) {
            for (int j = 0; j < n; j++)
                a[i][j] = 1;
        }
        if (rowOr[i] && r[i] == 0) {
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        if (colOr[j] == false && c[j]) {
            for (int i = 0; i < n; i++) 
                a[i][j] = 1;
        }
        if (colOr[j] && c[j] == 0) {
            for (int i = 0; i < n; i++)
                a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (r[i] == c[j]) 
                a[i][j] = r[i];
}

void check() {

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (j > 0) cerr << " ";
    //         cerr << ans[i][j];
    //     }
    //     cerr << endl;
    // }

    for (int i = 0; i < n; i++) {
        ull orVal = 0, andVal = ans[i][0];
        for (int j = 0; j < n; j++) {
            orVal |= ans[i][j];
            andVal &= ans[i][j];
        }
        if (rowOr[i]) {
            if (orVal != rows[i])
                return;
        } else {
            if (andVal != rows[i])
                return;
        }
    }

    for (int j = 0; j < n; j++) {
        ull orVal = 0, andVal = ans[0][j];
        for (int i = 0; i < n; i++) {
            orVal |= ans[i][j];
            andVal &= ans[i][j];
        }
        if (colOr[j]) {
            if (orVal != cols[j])
                return;
        } else {
            if (andVal != cols[j])
                return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    exit(0);
}

void bad() {
    puts("-1");
    exit(0);
}

void solve() {
    doIt();

    for (int i = 0; i < n; i++) {
        if (rowOr[i] && r[i] == 1) {
            int curOr = 0;
            for (int j = 0; j < n; j++)
                curOr |= a[i][j];
            if (curOr == 1)
                continue;

            for (int j = 0; j < n; j++) {
                if (colOr[j] == false && c[j] == 0) {
                    int newVal = 1;
                    for (int k = 0; k < n; k++)
                        if (k != i) newVal &= a[k][j];

                    if (newVal != 1) {
                        a[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    for (int j = 0; j < n; j++)
        if (colOr[j] && c[j] == 1) {
            int curOr = 0;
            for (int i = 0; i < n; i++)
                curOr |= a[i][j];
            if (curOr == 1)
                continue;

            for (int i = 0; i < n; i++)
                if (rowOr[i] == false && r[i] == 0) {
                    int newVal = 1;
                    for (int k = 0; k < n; k++)
                        if (k != j) newVal &= a[i][k];

                    if (newVal != 1) {
                        a[i][j] = 1;
                        break;
                    }   
                }
        }
}

int getBit(ull x, int pos) {
  return (x & (1ull << pos)) > 0 ? 1 : 0;
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &rowOr[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &colOr[i]);

    for (int i = 0; i < n; i++) 
        cin >> rows[i];
    for (int i = 0; i < n; i++) 
        cin >> cols[i];

    ull p = 1;
    for (int bit = 0; bit < 64; bit++) {
        for (int i = 0; i < n; i++) {
            r[i] = getBit(rows[i], bit);
        }
        for (int j = 0; j < n; j++) {
            c[j] = getBit(cols[j], bit);
        }
        solve();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                ans[i][j] += p * a[i][j];
            }
        p <<= 1;
    }

    check();
    bad();

    return 0;
}
