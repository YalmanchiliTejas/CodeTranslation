#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

vector<ll> B, P;

ll rec(int N, ll X) {
    if (X < 1) return 0;
    else if (N == 0) return 1;
    else if (X <= 1 + B[N - 1]) return rec(N - 1, X - 1);
    else if (X == 2 + B[N - 1]) return P[N - 1] + 1;
    else if (X <= 2 + 2 * B[N - 1]) return P[N - 1] + 1 + rec(N - 1, X - 2 - B[N - 1]);
    else return P[N - 1] * 2 + 1;
}

int main() {
    int N; ll X; cin >> N >> X;
    
    B.resize(N); P.resize(N);
    B[0] = P[0] = 1;
    REP(i, 1, N) {
        B[i] = B[i - 1] * 2 + 3;
        P[i] = P[i - 1] * 2 + 1;
    }

    cout << rec(N, X) << endl;
    return 0;
}