#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
    // dp
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> dp;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto it = upper_bound(dp.begin(), dp.end(), -A[i]);
        if (it == dp.end()) {
            ans++; dp.push_back(-A[i]);
        } else {
            *it = -A[i];
        }        
    }
    cout << sz(dp) << '\n';
    return 0;
}