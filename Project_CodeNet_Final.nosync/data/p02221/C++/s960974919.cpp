#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
int N; string S; vector<int> P;
int memo[1 << 18][19];
int winner(int a, int b) {
    int x = P[a], y = P[b];
    if (x > y) swap(x, y), swap(a, b);
    return (S[y - x - 1] == '0' ? a : b);
}
int f(int a, int b, int n) {
    a = (a + (1 << N)) % (1 << N);
    b = (b + (1 << N)) % (1 << N);
    if (memo[a][n] != -1) return memo[a][n];
    if (n == 1) {
        return memo[a][n] = winner(a, b);
    } else {
        int s = f(a, a + (1<<n)/2 - 1, n-1);
        int t = f(a + (1<<n)/2, b, n-1);
        return memo[a][n] = winner(s, t);
    }
}
int main() {
    cin >> N >> S;
    P.resize(1 << N); for (auto &p : P) cin >> p;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j <= N; j++) {
            memo[i][j] = -1;
        }
    }
    for (int k = 0; k < (1 << N); k++) {
        cout << P[f(k, k - 1, N)] << '\n';
    }
    return 0;
}
