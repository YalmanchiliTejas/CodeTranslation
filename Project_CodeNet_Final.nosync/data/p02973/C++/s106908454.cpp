#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    deque<int> dq;
    rep(i, 0, N) {
        int p = lower_bound(dq.begin(), dq.end(), A[i]) - dq.begin();
        if(p == 0) dq.push_front(A[i]);
        else dq[p-1] = A[i];
    }
    cout << dq.size() << endl;
    return 0;
}
