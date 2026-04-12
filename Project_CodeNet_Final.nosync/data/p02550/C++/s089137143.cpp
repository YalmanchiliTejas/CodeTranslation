//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << '\n';
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

template <typename T>
void print(const T &a) {
    for (auto e : a) cout << e << ' ';
    cout << '\n';
}

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    long long N, X, M; cin >> N >> X >> M;
    vector<vector<long long> > mov(61, vector<long long>(M));
    vector<vector<long long> > sum(61, vector<long long>(M));

    for (long long i = 0; i < M; i++) {
        mov[0][i] = i * i % M;
        sum[0][i] = i;
    }
    for (int i = 1; i < 61; i++) {
        for (int j = 0; j < M; j++) {
            mov[i][j] = mov[i-1][mov[i-1][j]];
            sum[i][j] = sum[i-1][j] + sum[i-1][mov[i-1][j]];
        }
    }

    long long ans = 0, pos = X;
    for (int i = 0; i < 61; i++) {
        if (N & 1LL<<i) {
            ans += sum[i][pos];
            pos = mov[i][pos];
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}