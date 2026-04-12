#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    long long N, X, M; cin >> N >> X >> M;
    vector<bool> B(M, 0);
    long long Cur = X;
    long long Ans = 0;
    vector<long long> S;
    while (N-- && Cur != 0) {
        Ans += Cur;
        if (B[Cur]) {
            vector<long long> Loop = {Cur};
            long long LoopSum = Cur;
            while (Cur != S.back()) {
                Loop.emplace_back(S.back());
                LoopSum += S.back();
                S.pop_back();
            }
            Ans += LoopSum * (N / Loop.size());
            N %= Loop.size();
            reverse(Loop.begin(), Loop.end());
            for (int i = 0; i < N; i++) Ans += Loop[i];
            break;
        } else {
            B[Cur] = 1;
            S.emplace_back(Cur);
            Cur = Cur * Cur % M;
        }
    }
    cout << Ans << "\n";
    return 0;
}