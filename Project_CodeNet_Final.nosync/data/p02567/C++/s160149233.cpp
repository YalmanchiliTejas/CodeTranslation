#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using namespace atcoder;

typedef long long ll;

int V;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -1;
}

bool f(int x) {
    return x < V;
}

int main() {
    int N, Q, A, T, X;
    cin >> N >> Q;
    segtree<int, op, e> seg(N);
    rep(i, N) {
        cin >> A;
        seg.set(i, A);
    }
    rep(i, Q) {
        cin >> T >> X >> V;
        if (T == 1) {
            seg.set(X - 1, V);
        } else if (T == 2) {
            cout << seg.prod(X - 1, V) << "\n";
        } else {
            cout << seg.max_right<f>(X - 1) + 1 << "\n";
        }
    }
}