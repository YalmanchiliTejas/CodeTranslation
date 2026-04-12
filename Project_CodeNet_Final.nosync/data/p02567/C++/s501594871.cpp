#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -1;
}

int target;
bool f(int x) {
    return x < target;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    segtree<int, op, e> seg(A);
    for (int i = 0; i < Q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            a--;
            seg.set(a, b);
        } else if (t == 2) {
            a--;
            cout << seg.prod(a, b) << endl;
        } else {
            a--;
            target = b;
            // auto f = [&](int x) { return x < b; };
            cout << seg.max_right<f>(a) + 1 << endl;
        }
    }
}
