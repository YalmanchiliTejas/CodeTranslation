#include <vector>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <climits>

using namespace std;
typedef long long ll;

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

template <class T>
T remin(T &x, T val) {
    if (x > val) {x = val;}
    return x;
}

template <class T>
T remax(T &x, T val) {
    if (x < val) {x = val;}
    return x;
}
using pii = pair<int, int>;

struct F{
    int a, b, c;
};

void solve() {
    int n = nxt();
    int m = nxt();
    vector<vector<int> > d(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = nxt();
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (d[i][j + 1] < d[i][j]) {
                cout << "Impossible\n";
                return;
            }
        }
    }

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i + 1][j] < d[i][j]) {
                cout << "Impossible\n";
                return;
            }
        }
    }

    vector<F> v;
    const int T = 101;
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) {
            int k = -10000;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    int cd = (x + 1) * i + (y + 1) * j;
                    int delta = d[x][y] - cd;
                    k = max(k, delta);
                }
            }
            if (k >= 0 && k < T) {
                v.push_back(F{i, j, k});
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            int val = 10000;
            for (const F&f : v) {
                int cv = f.a * (x + 1) + f.b * (y + 1) + f.c;
                assert(cv >= d[x][y]);
                val = min(val, cv);
            }
            if (val != d[x][y]) {
                cout << "Impossible\n";
                return;
            }
        }
    }

    const int N = 300;
    int t = N - 1;
    int dd[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dd[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < T; ++i) {
        dd[i][i + 1] = -1;
    }

    int YY = T + 1;
    for (int i = 0; i < T; ++i) {
        dd[i + YY][i + 1 + YY] = -2;
    }
    dd[YY + T][N - 1] = 0;

    for (const auto &f : v) {
        dd[f.a][YY + T - f.b] = f.c;
    }

    cout << "Possible" << "\n";
    int esize = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dd[i][j] < INT_MAX) {
                esize++;
            }
        }
    }
    cout << t + 1 << " " << esize << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dd[i][j] < INT_MAX) {
                cout << i + 1 << " " << j + 1 << " ";
                if (dd[i][j] >= 0) {
                    cout << dd[i][j];
                } else if (dd[i][j] == -1) {
                    cout << "X";
                } else {
                    cout << "Y";
                }
                cout << "\n";
            }
        }
    }
    cout << 1 << " " << N << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "r", stdout);
#endif

//    int t = nxt();
//    for (int i = 0; i < t; ++i) {
//        solve();
//    }
    solve();
    return 0;
}
