#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; int64_t X;
    cin >> N >> X;
    vector<int64_t> BP(N + 1), P(N + 1);
    BP[0] = 1, P[0] = 1;
    for(int i = 0; i < N; ++i) {
        BP[i + 1] = BP[i] * 2 + 3;
        P[i + 1] = P[i] * 2 + 1;
    }
    auto f = [&](auto &&f, int l, int64_t x) -> int64_t {
        if(l == 0) return 1;
        if(x == 1) return 0;
        else if(x <= BP[l-1] + 1) return f(f, l-1, x-1);
        else if(x == BP[l-1] + 2) return P[l-1] + 1;
        else if(x <= BP[l-1] * 2 + 2) return P[l-1] + f(f, l-1, x-(BP[l-1]+2)) + 1;
        else return P[l];
    };
    cout << f(f, N, X) << '\n';
    return 0;
}
