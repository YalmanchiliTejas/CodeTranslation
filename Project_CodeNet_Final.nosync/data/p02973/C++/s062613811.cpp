//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    deque<int> deq;
    deq.push_back(A[0]);

    int ans = 1;

    for (int i = 1; i < N; i++) {
        if (A[i] <= deq[0]) {
            ans++;
            deq.push_front(A[i]);
        }
        else {
            auto it = lower_bound(deq.begin(), deq.end(), A[i]);
            *(it - 1) = A[i];
        }
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}