#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
int main() {
    Int K; cin >> K;
    Int F = 0, E = 0, S = 0, T = 0, I = 0, V = 0, A = 0;
    vector<Int> L(500), C(500);
    for (int i = 0; i < 500; i++) {
        F += 1;
        E += F;
        S += E;
        T += S;
        I += T;
        V += I;
        A += V;
        L[i] = A;
    }
    for (int i = L.size() - 1; i >= 0; i--) {
        C[i] = K / L[i];
        K %= L[i];
    }
    for (int i = 0; i < 500; i++) {
        cout << "FESTIVA";
        for (int j = 0; j < C[i]; j++) {
            cout << 'L';
        }
    }
    cout << '\n';
    return 0;
}