#include <atcoder/segtree>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -1LL;
}

ll M;

bool f(ll x) {
    return x < M;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    atcoder::segtree<ll, op, e> sgt(A);

    for (int q = 0; q < Q; q++) {
        int T;
        scanf("%d", &T);
        if (T == 1) {
            int X;
            ll V;
            scanf("%d %lld", &X, &V);
            sgt.set(X-1, V);
        }
        if (T == 2) {
            int L, R;
            scanf("%d %d", &L, &R);
            printf("%lld\n", sgt.prod(L-1, R));
        }
        if (T == 3) {
            int X;
            scanf("%d %lld", &X, &M);
            printf("%d\n", sgt.max_right<f>(X-1)+1);
        }
    }
}