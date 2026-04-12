#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll N;
vector<ll> A;

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    deque<ll> dq;
    rep(i, N) {
        ll idx = lower_bound(dq.begin(), dq.end(), A[i]) - dq.begin();
        if (idx == 0) {
            dq.push_front(A[i]);
        } else {
            dq[idx - 1] = A[i];
        }
    }

    cout << dq.size() << endl;
}