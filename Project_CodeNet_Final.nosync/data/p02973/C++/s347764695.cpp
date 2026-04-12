#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    deque<int> deq;
    for (int i = 0; i < N; i++) {
        int pos = int(lower_bound(deq.begin(), deq.end(), A[i]) - deq.begin());
        if (pos == 0) {
            deq.push_front(A[i]);
        } else {
            deq[pos - 1] = A[i];
        }
    }

    cout << deq.size() << endl;
    return 0;
}