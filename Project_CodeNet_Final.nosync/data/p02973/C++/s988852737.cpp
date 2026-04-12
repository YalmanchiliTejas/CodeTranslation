#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    multiset<int> M;
    for (int i = 0; i < N; i++) {
        auto it = M.upper_bound(A[i] - 1);
        if (it == M.begin()) {
            M.insert(A[i]);
        } else {
            advance(it, -1);
            M.erase(it);
            M.insert(A[i]);
        }

        // for(auto e : M) {
        //     cout << e << " ";
        // }
        // cout << endl;
    }
    cout << M.size() << endl;
}

int main() {
    #ifdef LOCAL_ENV
    cin.exceptions(ios::failbit);
    #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    
    solve();
}