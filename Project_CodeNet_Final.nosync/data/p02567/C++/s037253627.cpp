#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int op(int a, int b) {
    return max(a, b);
}

int INF() {
    return numeric_limits<int>::min();
}

int target;
bool f(int v) {
    return v < target;
}

int main(void) {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    segtree<int, op, INF> seg(A);

    while(Q--) {
        int T;
        cin >> T;
        if(T == 1) {
            int X, V;
            cin >> X >> V;
            --X;
            seg.set(X, V);
        } else if(T == 2) {
            int L, R;
            cin >> L >> R;
            --L, --R;
            cout << seg.prod(L, R+1) << endl;
        } else if(T == 3) {
            int X;
            cin >> X >> target;
            --X;
            cout << seg.max_right<f>(X) + 1 << endl;
        }
    }
    return 0;
}
