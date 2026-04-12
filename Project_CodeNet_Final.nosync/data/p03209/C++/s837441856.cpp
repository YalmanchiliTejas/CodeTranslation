#include <iostream>
#include <vector>
using namespace std;

// バーガーの長さ L とパティー数 S
vector<long long> L, S;

// 再帰関数
long long rec(int N, long long X) {
    if (N == 0) return 1;

    if (X == 1) return 0;
    else if (X <= L[N-1] + 1) return rec(N-1, X-1);
    else if (X == L[N-1] + 2) return S[N-1] + 1;
    else if (X <= L[N-1] * 2 + 2) 
        return rec(N-1, X - L[N-1] - 2) + S[N-1] + 1;
    else return S[N-1] * 2 + 1;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;

    // L と S を予め求めておく
    L.assign(N+1, 1), S.assign(N+1, 1);
    for (int n = 1; n <= N; ++n) {
        L[n] = L[n-1] * 2 + 3;
        S[n] = S[n-1] * 2 + 1;
    }

    cout << rec(N, X) << endl;
}