#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i < ((int)(b)); ++i)
#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define sz(c) ((int)c.size())
#define all(c) c.begin(), c.end()

int paties[60];

int calc(int level, int l, int r, int X) {
    int m = (l + r - 1) / 2;
    
    if (level == 0) {
        return l < r;
    }

    if (X == l) {
        return 0;
    } else if (X == m) {
        return paties[level - 1] + 1;
    } else if (X == r - 1) {
        return paties[level - 1] * 2 + 1;
    } else if (m < X) {
        return paties[level - 1] + 1 + calc(level - 1, m + 1, r - 1, X);
    } else {
        assert(1 <= X && X < m);
        return calc(level - 1, l + 1, m, X);
    }
}

signed main() {
    int N, X;
    cin >> N >> X;
    X--;

    {
        int L = 1;
        for (int i = 0; i < 60; ++i) {
            paties[i] = L;
            L *= 2;
            L += 1;
        }
    }

    int L = 1;
    for (int i = 0; i < N; ++i) {
        L *= 2;
        L += 3;
    }
    cout << calc(N, 0, L, X) << endl;
}

