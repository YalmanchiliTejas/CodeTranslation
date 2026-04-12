#include <bits/stdc++.h>
using namespace std;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
using Int = long long;
int main() {
    Int N, X, M; cin >> N >> X >> M;
    vector<vector<Int>> A(M + 1, vector<Int>(40)), S(M + 1, vector<Int>(40));
    for (int i = 0; i < M; i++) {
        A[i][0] = (Int)i * i % M;
        S[i][0] = i;
    }
    for (int t = 1; t < 40; t++) {
        for (int i = 0; i < M; i++) {
            A[i][t] = A[A[i][t-1]][t-1];
            S[i][t] = S[i][t-1] + S[A[i][t-1]][t-1];
        }
    }
    Int ans = 0;
    Int val = X;
    for (int t = 39; t >= 0; t--) {
        if (N >= (1LL << t)) {
            ans += S[val][t];
            val = A[val][t];
            N -= (1LL << t);
        }
    }
    cout << ans << endl;
    return 0;
}
