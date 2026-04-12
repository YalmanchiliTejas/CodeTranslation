#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int64_t N, X, M;
    cin >> N >> X >> M;

    vector<int64_t> A(M);
    A[0] = X;
    rep(i, M - 1) A[i + 1] = A[i] * A[i] % M;

    vector<int64_t> cum(M + 1);
    rep(i, M) cum[i + 1] += cum[i] + A[i];

    if(N <= M) {
        cout << cum[N] << '\n';
        return 0;
    }

    int s = 0, l = 1;
    map<int64_t, int> id;
    rep(i, M) {
        if(id.find(A[i]) != id.end()) {
            s = id[A[i]];
            l = i - s;
            break;
        }
        id[A[i]] = i;
    }

    N -= s + l;
    int64_t ans = cum[s + l];
    ans += (cum[s + l] - cum[s]) * (N / l);
    ans += cum[s + N % l] - cum[s];
    cout << ans << '\n';
}
