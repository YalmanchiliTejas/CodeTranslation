#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    deque<long long> que; que.push_back(A[0]);
    int l = 1, r = N-1;
    while (l != r) {
        long long L = que.front(), R = que.back();
        long long a1 = abs(A[l]-L), a2 = abs(A[l]-R), a3 = abs(A[r]-L), a4 = abs(A[r]-R);
        long long mx = max({a1, a2, a3, a4});
        if (mx == a1) {
            que.push_front(A[l]);
            l++;
        } else if (mx == a2) {
            que.push_back(A[l]);
            l++;
        } else if (mx == a3) {
            que.push_front(A[r]);
            r--;
        } else if (mx == a4) {
            que.push_back(A[r]);
            r--;
        }
    }
    long long M = A[l];
    long long a1 = abs(M-que.front()), a2 = abs(M-que.back());
    if (a1 < a2) que.push_back(M);
    else que.push_front(M);
    
    long long now = que.front(); que.pop_front();
    long long ans = 0;
    while (!que.empty()) {
        long long nxt = que.front(); que.pop_front();
        ans += abs(now-nxt); now = nxt;
    }
    
    cout << ans << endl;
    return 0;
}